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

$(_OBJDIR)/dynamicArtInfo.o: dynamicArtInfo.cpp dynamicArtInfo.h
	$(CC) -c $(CFLAGS) dynamicArtInfo.cpp -o $@

$(_OBJDIR)/dynamicArtDB.o: dynamicArtDB.cpp dynamicArtDB.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn dynamicArtDB.cpp -o $@

$(_OBJDIR)/dynamicArt.o: dynamicArt.cpp httplib.h
	$(CC) -c $(CFLAGS) dynamicArt.cpp -o $@

GalleryArtProject: $(_OBJDIR)/userInfo.o $(_OBJDIR)/userDB.o $(_OBJDIR)/responseInfo.o $(_OBJDIR)/responseDB.o $(_OBJDIR)/artProject.o
	$(CC) $(_OBJDIR)/userInfo.o $(_OBJDIR)/userDB.o $(_OBJDIR)/responseInfo.o $(_OBJDIR)/responseDB.o $(_OBJDIR)/artProject.o -o GalleryArtProject -L/usr/local/lib -lmariadbcpp

PutHTML:
	cp artProjectHome.html /var/www/html/galleryArtProject/
	cp learnMore.html /var/www/html/galleryArtProject/
	cp artWork.html /var/www/html/galleryArtProject/
	cp artProject.js /var/www/html/galleryArtProject/
	cp style.css /var/www/html/galleryArtProject/
	
	cp responsePages/Berlant_Drummer.html /var/www/html/galleryArtProject/
	cp responsePages/Bulkeley_Warbler.html /var/www/html/galleryArtProject/
	cp responsePages/Christo_WrappedReichstag.html /var/www/html/galleryArtProject/
	cp responsePages/Davis_Paulo.html /var/www/html/galleryArtProject/
	cp responsePages/bustOfVictoria.html /var/www/html/galleryArtProject/
	cp responsePages/McPhee_Flareups.html /var/www/html/galleryArtProject/
	cp responsePages/McPhee_QuarteredElk.html /var/www/html/galleryArtProject/
	cp responsePages/Moore_SpindlePiece.html /var/www/html/galleryArtProject/
	cp responsePages/Stella_SatBhai.html /var/www/html/galleryArtProject/
	cp responsePages/Surls_WhiteTippedBlooming.html /var/www/html/galleryArtProject/
	cp responsePages/aprilAndDaughter.html /var/www/html/galleryArtProject/
	cp responsePages/peaceThroughChemistry.html /var/www/html/galleryArtProject/
	
	cp dynamicArt.html /var/www/html/galleryArtProject/
	cp dynamicArt.js /var/www/html/galleryArtProject/
	
	@echo "Current contents of your HTML directory: "
	@ls -l /var/www/html/galleryArtProject

clean:
	$(RM) $(_OBJDIR)/*.o GalleryArtProject

