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

BINARIES="testOneWidget "
BINARIES="$BINARIES testWidget "
BINARIES="$BINARIES testLabel "
BINARIES="$BINARIES testButton "
BINARIES="$BINARIES testTextBox "
BINARIES="$BINARIES testCheckBox "
BINARIES="$BINARIES testHorizontalMenu "
BINARIES="$BINARIES testVerticalMenu "
BINARIES="$BINARIES testContainer"
BINARIES="$BINARIES testWindow "
BINARIES="$BINARIES testPopupMenu "
BINARIES="$BINARIES testScreen "
BINARIES="$BINARIES testApp "
BINARIES="$BINARIES testChangeEvent "
# BINARIES="$BINARIES testMessageBox "
# BINARIES="$BINARIES testConfirmBox "
BINARIES="$BINARIES testRadioButton "
BINARIES="$BINARIES testSelectBox "
BINARIES="$BINARIES testTextArea "
BINARIES="$BINARIES testRadioGroup "
BINARIES="$BINARIES testScrollPane "
BINARIES="$BINARIES testLabelInScreen "

TESTOBJECTS="testOneWidget.o "
BINARIES="$BINARIES testWidget.o "
BINARIES="$BINARIES testLabel.o "
TESTOBJECTS="$TESTOBJECTS testButton.o "
BINARIES="$BINARIES testTextBox.o "
BINARIES="$BINARIES testCheckBox.o "
TESTOBJECTS="$TESTOBJECTS testHortizontalMenu.o "
BINARIES="$BINARIES testVerticalMenu.o "
BINARIES="$BINARIES testContainer.o"
TESTOBJECTS="$TESTOBJECTS testWindow.o "
BINARIES="$BINARIES testPopupMenu.o "
TESTOBJECTS="$TESTOBJECTS testScreen.o "
TESTOBJECTS="$TESTOBJECTS testApp.o "
TESTOBJECTS="$TESTOBJECTS testChangeEvent.o "
# TESTOBJECTS="$TESTOBJECTS testMessageBox.o "
# TESTOBJECTS="$TESTOBJECTS testConfirmBox.o "
TESTOBJECTS="$TESTOBJECTS testRadioButton.o "
TESTOBJECTS="$TESTOBJECTS testSelectBox.o "
TESTOBJECTS="$TESTOBJECTS testTextArea.o "
TESTOBJECTS="$TESTOBJECTS testRadioGroup.o "
TESTOBJECTS="$TESTOBJECTS testScrollPane.o "
TESTOBJECTS="$TESTOBJECTS testLabelInScreen.o "
