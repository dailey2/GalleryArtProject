# GalleryArtProject

A REST based dynamic art word cloud application using C++ and JavaScript.

This project visualizes emotions associated with artworks using a word cloud. 
The word cloud displays emotions with varying font sizes and colors based on the 
number of responses in the database.

## Prerequisites

### cpp-httplib

Uses cpp-httplib for the microservice.
https://github.com/yhirose/cpp-httplib

Install SSL and compression services:
```sh
sudo apt-get install libssl-dev
sudo apt-get install libz-dev
```

### MariaDB

This assumes MariaDB is installed. If not, follow these instructions: https://www.digitalocean.com/community/tutorials/how-to-install-mariadb-on-ubuntu-22-04

Install the MariaDB connector: https://mariadb.com/docs/skysql/connect/programming-languages/cpp/install/

### Set JavaScript IP address to your VM address
Edit dynamicArt.js and artProject.js so that baseUrl is your VM's IP address.

## Set up App

### Create a directory for the application:

```sh
sudo mkdir /var/www/html/GalleryArtProject/
sudo chown ubuntu /var/www/html/GalleryArtProject/
```

### Build and Run
To build the application, run:
```sh
make
```

To start the application, run:
```sh
./GalleryArtProject
```

## Access the Application
Go to your VM URL/GalleryArtProject/artProjectHome.html or URL/GalleryArtProject/dynamicArt.html

