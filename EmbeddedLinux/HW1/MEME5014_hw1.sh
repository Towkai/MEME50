#!/bin/sh

DISK="$1"
#DISK=/dev/sdb

if [ -z "${DISK}" ]; then
	echo "Please input the block devcie name"
	echo "Usage: ./part_disk.sh /dev/sdb"

	exit 0
fi

parted ${DISK} --script mklabel msdos
parted -a optimal ${DISK} --script mkpart primary fat32 8192s 133192s
parted name 1 Boot
parted -a optimal ${DISK} --script mkpart primary ext4 133192s 250000s
parted name 2 MEME5014
mkfs.vfat -n BOOT -F 32 ${DISK}1
yes| mkfs.ext4 -L root ${DISK}2

mkdir  -p /mnt/p1 /mnt/p2
mount "${DISK}1" /mnt/p1
mount "${DISK}2" /mnt/p2

cp -a ~/bootloader/lab-create_a_bootable_system/boot/* /mnt/p1/
tar -xJvf ~/bootloader/lab-create_a_bootable_system/rootfs.tar.xz
cp -a ~/bootloader/lab-create_a_bootable_system/rootfs/* /mnt/p2/