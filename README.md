# MC145192 PLL library

## Introduction

This library is used to control Motorola MC145192 PLL frequency synthesizer, which is
used in some VHF/UHF handheld transceivers.

The MC145192 is a low–voltage single–package synthesizer with serial interface capable 
of direct usage up to 1.1 GHz. Controlled using SPI bus.

MC145192 specification - http://pdf.datasheetcatalog.com/datasheet/motorola/MC145192.pdf

## Usage

    #include <SPI.h>
    #include <MC145192.h> 
    
    MC145192 PLL(CS_PIN);
   
    void setup(){        
        // TBD
    }
    
