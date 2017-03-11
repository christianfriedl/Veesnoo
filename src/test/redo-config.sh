#!/bin/bash

CC=clang++
CFLAGS="-g -I../ -Wall -std=c++14 "
CFLAGS="$CFLAGS `pkg-config --cflags sigc++-2.0`"

. ../redo-config.local.sh

. ../config-defines.sh

LDFLAGS="$CURSESLIB -L../ -std=c++14"
LDFLAGS="$LDFLAGS `pkg-config --libs sigc++-2.0`"

STATIC_LIBS=-lnvwm
LIBOBJS=../libnvwm.a

BINARIES="testOneWidget testWidget testLabel "
BINARIES="$BINARIES testButton testTextBox testCheckbox "
BINARIES="$BINARIES testHorizontalMenu testVerticalMenu testContainer"
BINARIES="$BINARIES testWindow testPopupMenu "
BINARIES="$BINARIES testScreen testApp testChangeEvent "
BINARIES="$BINARIES testMessageBox "
BINARIES="$BINARIES testConfirmBox "
# BINARIES="$BINARIES testRadioButton "

TESTOBJECTS="testOneWidget.o testWidget.o testLabel.o "
TESTOBJECTS="$TESTOBJECTS testButton.o testTextBox.o testCheckbox.o "
TESTOBJECTS="$TESTOBJECTS testHortestConfirmBox.o testVerticalMenu.o testContainer.o"
TESTOBJECTS="$TESTOBJECTS testWindow.o testPopupMenu.o "
TESTOBJECTS="$TESTOBJECTS testScreen.o testApp.o testChangeEvent.o "
TESTOBJECTS="$TESTOBJECTS testMessageBox.o "
TESTOBJECTS="$TESTOBJECTS testConfirmBox.o "
# TESTOBJECTS="$TESTOBJECTS testRadioButton.o "
