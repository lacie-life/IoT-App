#! /bin/bash

#			HUONG DAN SU DUNG SCRIPT			#
#				   vvv					#
#									#
#   BUOC 1: SUA BIEN (BUILD_DIR) BEN DUOI THANH PATH TOI FOLDER BUILD
#   BUOC 2: SUA BIEN (DEST_DIR) BEN DUOI THANH PATH TOI FOLDER RELEASE APP
#	    -> MAC DINH SE LA FOLDER: ReleaseApp tren Desktop


# MAIN SCRIPT
BUILD_DIR="$HOME/Working/Release/IoT-App"
APP_NAME="IoT-Dashboard"
DEST_DIR="$HOME/Desktop/ReleaseApp"

clear
echo -e -n "\033[1;36m"
if ! [ -d $DEST_DIR ]
then
	mkdir "$DEST_DIR"
        echo -e "RELEASE DIRECTORY DOES NOT EXIST >>> \033[1;32mCREATE"
else
        echo -e "RELEASE DIRECTORY EXISTS >>> \033[1;32mCONTINUE"
fi

scp -r "$BUILD_DIR/share/" "$DEST_DIR"
scp "$BUILD_DIR/$APP_NAME" "$DEST_DIR"

echo -e "\033[00m"
echo -e -n "\033[1;33mOn:\033[00m" && date +"  %B %d, %Y"
echo -e -n "\033[1;33mAt:\033[00m" && date +"  %Hh-%Mm-%Ss"
echo -e "\033[1;33m>>>  RELEASE DONE"
echo "         "
echo -e "\033[1;32mRELEASE DIRECTORY >>> \033[00m$DEST_DIR"
echo

# REMOVE SCRIPT IN RELEASE FOLDER
rm -r "$DEST_DIR/share/script"
