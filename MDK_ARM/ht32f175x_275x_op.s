;/*****************************************************************************/
;/* ht32f175x_275x_op.s: HT32F175x/275x Flash Option Bytes Block              */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/

;// <e> Setting of Flash protection
;// <i> Setting of Page erase/program protection and security protection of Flash (configured in Option Byte)
FLASH_OPT     EQU     0

;// <h> Page erase/program protection of Main Flash
;// <i> Enable page erase/program protection to prevent unwanted change of Flash contents
;//   <o0.0 > Enable page 0 erase/Program Protection
;//   <o0.1 > Enable page 1 erase/Program Protection
;//   <o0.2 > Enable page 2 erase/Program Protection
;//   <o0.3 > Enable page 3 erase/Program Protection
;//   <o0.4 > Enable page 4 erase/Program Protection
;//   <o0.5 > Enable page 5 erase/Program Protection
;//   <o0.6 > Enable page 6 erase/Program Protection
;//   <o0.7 > Enable page 7 erase/Program Protection
;//   <o0.8 > Enable page 8 erase/Program Protection
;//   <o0.9 > Enable page 9 erase/Program Protection
;//   <o0.10 > Enable page 10 erase/Program Protection
;//   <o0.11 > Enable page 11 erase/Program Protection
;//   <o0.12 > Enable page 12 erase/Program Protection
;//   <o0.13 > Enable page 13 erase/Program Protection
;//   <o0.14 > Enable page 14 erase/Program Protection
;//   <o0.15 > Enable page 15 erase/Program Protection
;//   <o0.16 > Enable page 16 erase/Program Protection
;//   <o0.17 > Enable page 17 erase/Program Protection
;//   <o0.18 > Enable page 18 erase/Program Protection
;//   <o0.19 > Enable page 19 erase/Program Protection
;//   <o0.20 > Enable page 20 erase/Program Protection
;//   <o0.21 > Enable page 21 erase/Program Protection
;//   <o0.22 > Enable page 22 erase/Program Protection
;//   <o0.23 > Enable page 23 erase/Program Protection
;//   <o0.24 > Enable page 24 erase/Program Protection
;//   <o0.25 > Enable page 25 erase/Program Protection
;//   <o0.26 > Enable page 26 erase/Program Protection
;//   <o0.27 > Enable page 27 erase/Program Protection
;//   <o0.28 > Enable page 28 erase/Program Protection
;//   <o0.29 > Enable page 29 erase/Program Protection
;//   <o0.30 > Enable page 30 erase/Program Protection
;//   <o0.31 > Enable page 31 erase/Program Protection
;//   <o1.0 > Enable page 32 erase/Program Protection
;//   <o1.1 > Enable page 33 erase/Program Protection
;//   <o1.2 > Enable page 34 erase/Program Protection
;//   <o1.3 > Enable page 35 erase/Program Protection
;//   <o1.4 > Enable page 36 erase/Program Protection
;//   <o1.5 > Enable page 37 erase/Program Protection
;//   <o1.6 > Enable page 38 erase/Program Protection
;//   <o1.7 > Enable page 39 erase/Program Protection
;//   <o1.8 > Enable page 40 erase/Program Protection
;//   <o1.9 > Enable page 41 erase/Program Protection
;//   <o1.10 > Enable page 42 erase/Program Protection
;//   <o1.11 > Enable page 43 erase/Program Protection
;//   <o1.12 > Enable page 44 erase/Program Protection
;//   <o1.13 > Enable page 45 erase/Program Protection
;//   <o1.14 > Enable page 46 erase/Program Protection
;//   <o1.15 > Enable page 47 erase/Program Protection
;//   <o1.16 > Enable page 48 erase/Program Protection
;//   <o1.17 > Enable page 49 erase/Program Protection
;//   <o1.18 > Enable page 50 erase/Program Protection
;//   <o1.19 > Enable page 51 erase/Program Protection
;//   <o1.20 > Enable page 52 erase/Program Protection
;//   <o1.21 > Enable page 53 erase/Program Protection
;//   <o1.22 > Enable page 54 erase/Program Protection
;//   <o1.23 > Enable page 55 erase/Program Protection
;//   <o1.24 > Enable page 56 erase/Program Protection
;//   <o1.25 > Enable page 57 erase/Program Protection
;//   <o1.26 > Enable page 58 erase/Program Protection
;//   <o1.27 > Enable page 59 erase/Program Protection
;//   <o1.28 > Enable page 60 erase/Program Protection
;//   <o1.29 > Enable page 61 erase/Program Protection
;//   <o1.30 > Enable page 62 erase/Program Protection
;//   <o1.31 > Enable page 63 erase/Program Protection
;//   <o2.0 > Enable page 64 erase/Program Protection
;//   <o2.1 > Enable page 65 erase/Program Protection
;//   <o2.2 > Enable page 66 erase/Program Protection
;//   <o2.3 > Enable page 67 erase/Program Protection
;//   <o2.4 > Enable page 68 erase/Program Protection
;//   <o2.5 > Enable page 69 erase/Program Protection
;//   <o2.6 > Enable page 70 erase/Program Protection
;//   <o2.7 > Enable page 71 erase/Program Protection
;//   <o2.8 > Enable page 72 erase/Program Protection
;//   <o2.9 > Enable page 73 erase/Program Protection
;//   <o2.10 > Enable page 74 erase/Program Protection
;//   <o2.11 > Enable page 75 erase/Program Protection
;//   <o2.12 > Enable page 76 erase/Program Protection
;//   <o2.13 > Enable page 77 erase/Program Protection
;//   <o2.14 > Enable page 78 erase/Program Protection
;//   <o2.15 > Enable page 79 erase/Program Protection
;//   <o2.16 > Enable page 80 erase/Program Protection
;//   <o2.17 > Enable page 81 erase/Program Protection
;//   <o2.18 > Enable page 82 erase/Program Protection
;//   <o2.19 > Enable page 83 erase/Program Protection
;//   <o2.20 > Enable page 84 erase/Program Protection
;//   <o2.21 > Enable page 85 erase/Program Protection
;//   <o2.22 > Enable page 86 erase/Program Protection
;//   <o2.23 > Enable page 87 erase/Program Protection
;//   <o2.24 > Enable page 88 erase/Program Protection
;//   <o2.25 > Enable page 89 erase/Program Protection
;//   <o2.26 > Enable page 90 erase/Program Protection
;//   <o2.27 > Enable page 91 erase/Program Protection
;//   <o2.28 > Enable page 92 erase/Program Protection
;//   <o2.29 > Enable page 93 erase/Program Protection
;//   <o2.30 > Enable page 94 erase/Program Protection
;//   <o2.31 > Enable page 95 erase/Program Protection
;//   <o3.0 > Enable page 96 erase/Program Protection
;//   <o3.1 > Enable page 97 erase/Program Protection
;//   <o3.2 > Enable page 98 erase/Program Protection
;//   <o3.3 > Enable page 99 erase/Program Protection
;//   <o3.4 > Enable page 100 erase/Program Protection
;//   <o3.5 > Enable page 101 erase/Program Protection
;//   <o3.6 > Enable page 102 erase/Program Protection
;//   <o3.7 > Enable page 103 erase/Program Protection
;//   <o3.8 > Enable page 104 erase/Program Protection
;//   <o3.9 > Enable page 105 erase/Program Protection
;//   <o3.10 > Enable page 106 erase/Program Protection
;//   <o3.11 > Enable page 107 erase/Program Protection
;//   <o3.12 > Enable page 108 erase/Program Protection
;//   <o3.13 > Enable page 109 erase/Program Protection
;//   <o3.14 > Enable page 110 erase/Program Protection
;//   <o3.15 > Enable page 111 erase/Program Protection
;//   <o3.16 > Enable page 112 erase/Program Protection
;//   <o3.17 > Enable page 113 erase/Program Protection
;//   <o3.18 > Enable page 114 erase/Program Protection
;//   <o3.19 > Enable page 115 erase/Program Protection
;//   <o3.20 > Enable page 116 erase/Program Protection
;//   <o3.21 > Enable page 117 erase/Program Protection
;//   <o3.22 > Enable page 118 erase/Program Protection
;//   <o3.23 > Enable page 119 erase/Program Protection
;//   <o3.24 > Enable page 120 erase/Program Protection
;//   <o3.25 > Enable page 121 erase/Program Protection
;//   <o3.26 > Enable page 122 erase/Program Protection
;//   <o3.27 > Enable page 123 erase/Program Protection
;//   <o3.28 > Enable page 124 erase/Program Protection
;//   <o3.29 > Enable page 125 erase/Program Protection
;//   <o3.30 > Enable page 126 erase/Program Protection
;// </h>
PP0     EQU         0x00000000
PP1     EQU         0x00000000
PP2     EQU         0x00000000
PP3     EQU         0x00000000
nPP0    EQU         PP0:EOR:0xFFFFFFFF
nPP1    EQU         PP1:EOR:0xFFFFFFFF
nPP2    EQU         PP2:EOR:0xFFFFFFFF
nPP3    EQU         PP3:EOR:0xFFFFFFFF

;//   <o0.1> Enable Option Byte erase/program protection
;//   <i> Enable Option Byte erase/program protection to prevent unwanted change of Option Byte
;//   <o0.0> Enable security protection of Flash
;//   <i> Enable Security protection to prevent illegal Flash code/data access
CP      EQU         0x00000000
nCP     EQU         CP:EOR:0xFFFFFFFF


    IF nPP0 = 0xFFFFFFFF && nPP1 = 0xFFFFFFFF && nPP2 = 0xFFFFFFFF && nPP3 = 0xFFFFFFFF &&  nCP = 0xFFFFFFFF
CK      EQU         0xFFFFFFFF
    ELSE
CK      EQU         (nPP0 + nPP1 + nPP2 + nPP3 + nCP)
    ENDIF
RES     EQU         0xFFFFFFFF

;// </e>

                IF      FLASH_OPT <> 0
                AREA    |.ARM.__AT_0x1FF00000|, CODE, READONLY
                DCD   nPP0          ; 0x1FF00000
                DCD   nPP1          ; 0x1FF00004
                DCD   nPP2          ; 0x1FF00008
                DCD   nPP3          ; 0x1FF0000C
                DCD   nCP           ; 0x1FF00010
                DCD   RES           ; 0x1FF00014
                DCD   RES           ; 0x1FF00018
                DCD   RES           ; 0x1FF0001C
                DCD   CK            ; 0x1FF00020
                DCD   RES           ; 0x1FF00024
                DCD   RES           ; 0x1FF00028
                ENDIF

;// <e> Program Bootloader Options
BOOT_OPT      EQU     0
;//   <o> Bootloader Waiting time (mS) <1500-14200:50>
;//    <i> Bootloader Waiting time in mSecond
BOOTOPTV EQU        1500

    IF BOOT_OPT <> 0
BOOTOPT EQU         0xFFFFFF00:OR:(BOOTOPTV - 1500)/50
    ELSE
BOOTOPT EQU         0xFFFFFFFF
    ENDIF

                IF      BOOT_OPT <> 0
                AREA    |.ARM.__AT_0x1FF0002C|, CODE, READONLY
                DCD   BOOTOPT       ; 0x1FF0002C
                ENDIF

;// </e>

;// <e> Program user's Flash data into Option Byte
;// <i> Address range: from 0x1FF00050 to 0x1FF003FF (Max 944 Bytes)
FLASH_DATA      EQU     0
;// </e>
                IF      FLASH_DATA <> 0
                AREA    |.ARM.__AT_0x1FF00050|, CODE, READONLY
                INCBIN  userdata.dat
                ENDIF

                END
