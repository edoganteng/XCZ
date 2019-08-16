
Debian
====================
This directory contains files used to package xchainzd/xchainz-qt
for Debian-based Linux systems. If you compile xchainzd/xchainz-qt yourself, there are some useful files here.

## xchainz: URI support ##


xchainz-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install xchainz-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your xchainz-qt binary to `/usr/bin`
and the `../../share/pixmaps/xchainz128.png` to `/usr/share/pixmaps`

xchainz-qt.protocol (KDE)

