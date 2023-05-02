# Gallery Art Project
# Connor Dailey, Kenyon College 2023

CC = g++

# For Optimization
# CFLAGS = -O2
# For debugging
CFLAGS = -std=c++14 -Wno-deprecated-declarations

RM = /bin/rm -f

_OBJDIR = obj
$(shell mkdir -p $(_OBJDIR))

all: GalleryArtProject PutHTML

$(_OBJDIR)/userInfo.o: userInfo.cpp userInfo.h
	$(CC) -c $(CFLAGS) userInfo.cpp -o $@

$(_OBJDIR)/userDB.o: userDB.cpp userDB.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn userDB.cpp -o $@

$(_OBJDIR)/responseInfo.o: responseInfo.cpp responseInfo.h
	$(CC) -c $(CFLAGS) responseInfo.cpp -o $@

$(_OBJDIR)/responseDB.o: responseDB.cpp responseDB.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn responseDB.cpp -o $@

$(_OBJDIR)/artProject.o: artProject.cpp httplib.h
	$(CC) -c $(CFLAGS) artProject.cpp -o $@

GalleryArtProject: $(_OBJDIR)/userInfo.o $(_OBJDIR)/userDB.o $(_OBJDIR)/responseInfo.o $(_OBJDIR)/responseDB.o $(_OBJDIR)/artProject.o
	$(CC) $(_OBJDIR)/userInfo.o $(_OBJDIR)/userDB.o $(_OBJDIR)/responseInfo.o $(_OBJDIR)/responseDB.o $(_OBJDIR)/artProject.o -o GalleryArtProject -L/usr/local/lib -lmariadbcpp

PutHTML:
	cp artProjectHome.html /var/www/html/galleryArtProject/
	cp learnMore.html /var/www/html/galleryArtProject/
	cp artWork.html /var/www/html/galleryArtProject/
	cp artProject.js /var/www/html/galleryArtProject/
	cp style.css /var/www/html/galleryArtProject/
	cp project1.html /var/www/html/galleryArtProject/

	@echo "Current contents of your HTML directory: "
	@ls -l /var/www/html/galleryArtProject

clean:
	$(RM) $(_OBJDIR)/*.o GalleryArtProject

