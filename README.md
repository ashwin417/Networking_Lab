# Networking_Lab
### Welcome to My Networking-Lab Repository!!!!
    This is a repository for Networking-programs in C for my College Purpose!
    This repository contains code for Networking-program listed below and algorithm and code explanation for the programs.
    Most of the programs will work in Linux only.
    1. TCP Client-Server
    2. UDP Client-Server
    3. Time-server application
    4. Sliding-window protocols
            a. Stop and Wait ARQ
            b. Go Back N ARQ
    5. File Transfer Protocol (FTP)
    6. Congestion Control - Leaky Bucket Algorithm
    7. Distance Vector Routing Algorithm
    8. SMTP
    9. Other Miscellaneous Trials


#### PDF of Lab-Record -> [Network Lab Manual](https://github.com/ashwin417/Networking_Lab/blob/main/NWLabRecord.pdf)

## Syllabus (KTU Syllabus)
    *Mandatory 
    (Note: At least one program from each topic in the syllabus should be completed in the Lab)
        1. Getting started with the basics of network configuration files and networking
            commands in Linux.*
        2. To familiarize and understand the use and functioning of system calls used for
            network programming in Linux.*
        3. Implement client-server communication using socket programming and TCP as
            transport layer protocol*
        4. Implement client-server communication using socket programming and UDP as
        transport layer protocol*
        5. Simulate sliding window flow control protocols.* (Stop and Wait, Go back N,
            Selective Repeat ARQ protocols)
        6. Implement and simulate algorithm for Distance Vector Routing protocol or Link
        State Routing protocol.*
        7. Implement Simple Mail Transfer Protocol.
        8. Implement File Transfer Protocol.*
        9. Implement congestion control using a leaky bucket algorithm.*
        10. Understanding the Wireshark tool.*
        11. Design and configure a network with multiple subnets with wired and wireless LANs
        using required network devices. Configure commonly used services in the network.*
        12. Study of NS2 simulator*
        Networking Lab-Practice Questions
        1. a) View the configuration, including addresses of your computers network interfaces.
            b) Test the network connectivity between your computer and several other computers.
            c) View the active TCP connections in the computer after visiting a website.
            d) Find the hardware/MAC address of another computer in the network using ARP.
        2. Write the system calls used for creating sockets and transferring data between two
        nodes.
        3. a) Implement a multi-user chat server using TCP as transport layer protocol.
            b) Implement a simple web proxy server that accepts HTTP requests and forwarding
        to remote servers and returning data to the client using TCP200COMPUTER SCIENCE AND ENGINEERING
        4. Implement a Concurrent Time Server application using UDP to execute the program
        at a remote server. Client sends a time request to the server, server sends its system
        time back to the client. Client displays the result.
        5. a) Implement Stop-and-Wait ARQ flow control protocol.
        b) Implement Go-Back--N ARQ flow control protocol.
        c) Implement Selective Repeat ARQ flow control protocol.
        6. Implement Distance Vector Routing algorithm or Link State Routing algorithm..
        7. Implement Simple Mail Transfer Protocol.
        8. Develop a concurrent file server which will provide the file requested by a client if it
        exists. If not, the server sends appropriate message to the client. Server should also
        send its process ID (PID) to clients for display along with the file or the message.
        9. Implement leaky bucket algorithm for congestion control.
        10. a) Using Wireshark, Capture packets transferred while browsing a selected website.
        Investigate the protocols used in each packet, the values of the header fields and the
        size
        of the packet.
        b) Using Wireshark, observe three way handshaking connection establishment, three
        way handshaking connection termination and Data transfer in client server
        communication using TCP.
        c) Explore at least the following features of Wireshark: filters, Flow graphs (TCP),
        statistics, and protocol hierarchies.
        11. Design and configure a network (wired and wireless LANs) with multiple subnets
        using required network devices. Configure at least three of the following services in
        the network- TELNET, SSH, FTP server, Web server, File server, DHCP server and
        DNS server.
        12. a) The network consists of TCP source node (n0) and destination node (n1) over an
        area size of 500m x 500m. Node (n0) uses Agent/TCP/Reno as the sending TCP
        agent and FTP traffic source. Node (n1) is the receiver of FTP transfers, and it uses
        Agent/TCP sink as its TCP-agent for the connection establishment. Run the
        simulation for 150 seconds and show the TCP window size in two static nodes
        scenario with any dynamic routing protocol. Run the script and analyze the output
        graph for the given scenario.

        b) Simulate the transmission of ping messages over a star network topology consisting
        of ‘n’ nodes and find the number of packets dropped due to congestion using
        NS2simulator.

        c) Simulate Link State Protocol or Distance Vector Routing protocol in NS2.201COMPUTER SCIENCE AND ENGINEERING


### Reference Books:
        1. W. Richard Stevens, Bill Fenner, Andy Rudoff, UNIX Network Programming:
        Volume 1, The Sockets Networking API, 3rd Edition, Pearson, 2015

        2. Lisa Bock, Learn Wireshark: Confidently navigate the Wireshark interface and solve
        real-world networking problems, Packt Publishing, 2019

        3. Teerawat Issariyakul, Ekram Hossain, Introduction to Network Simulator NS2,2nd
        Edition, Springer,2019


### About
        Created by R Ashwin
        Year - 2023
        Powered by ChatGPT, VScode, Linux!!!