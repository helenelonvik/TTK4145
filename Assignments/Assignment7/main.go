package main

import (
	"encoding/binary"
	"fmt"
	"net"
	"os/exec"
	"time"
)

var counter uint64
var buffer = make([]byte, 1024)

func backup() {
	fmt.Println("... creating new backup ")
	cmd := exec.Command("cmd", "/C", "start go run main.go") // start go run main.go for å spawne
	cmd.Start()
	fmt.Println("... resuming from ", counter)
}

func main() {
	// set up and listen from UDP
	addr, _ := net.ResolveUDPAddr("udp", "127.0.0.1:1234")
	conn, err := net.ListenUDP("udp", addr)
	if err != nil {
		fmt.Printf("Some error 1%v\n", err)
	}
	fmt.Println(" --- Backup phase --- ")
	isBackup := true

	// check for primary (3 sek timeout)
	for isBackup {
		conn.SetReadDeadline(time.Now().Add(3 * time.Second))
		n, _, err := conn.ReadFromUDP(buffer)
		if err != nil {
			isBackup = false
			fmt.Println("... timed out ")
		} else {
			counter = binary.BigEndian.Uint64(buffer[:n])
		}
	}
	conn.Close()

	// Change to primary
	fmt.Println(" --- Primary phase --- ")
	broadcast, _ := net.DialUDP("udp", nil, addr)
	backup()
	for {
		counter += 1
		fmt.Println("Counter: ", counter)
		binary.BigEndian.PutUint64(buffer, counter)
		_, _ = broadcast.Write(buffer)
		time.Sleep(time.Second)
	}

}
