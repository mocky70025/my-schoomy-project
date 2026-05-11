                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.0 #15242 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _key
                                     13 	.globl _key_
                                     14 	.globl _msleep
                                     15 	.globl _EIPX6
                                     16 	.globl _EIPX5
                                     17 	.globl _EIPX4
                                     18 	.globl _PI2C
                                     19 	.globl _PUSB
                                     20 	.globl _EIEX6
                                     21 	.globl _EIEX5
                                     22 	.globl _EIEX4
                                     23 	.globl _EI2C
                                     24 	.globl _EUSB
                                     25 	.globl _SMOD1
                                     26 	.globl _ERESI
                                     27 	.globl _RESI
                                     28 	.globl _INT6
                                     29 	.globl _CY
                                     30 	.globl _AC
                                     31 	.globl _F0
                                     32 	.globl _RS1
                                     33 	.globl _RS0
                                     34 	.globl _OV
                                     35 	.globl _FL
                                     36 	.globl _P
                                     37 	.globl _TF2
                                     38 	.globl _EXF2
                                     39 	.globl _RCLK
                                     40 	.globl _TCLK
                                     41 	.globl _EXEN2
                                     42 	.globl _TR2
                                     43 	.globl _C_T2
                                     44 	.globl _CP_RL2
                                     45 	.globl _SM01
                                     46 	.globl _SM11
                                     47 	.globl _SM21
                                     48 	.globl _REN1
                                     49 	.globl _TB81
                                     50 	.globl _RB81
                                     51 	.globl _TI1
                                     52 	.globl _RI1
                                     53 	.globl _PS1
                                     54 	.globl _PT2
                                     55 	.globl _PS0
                                     56 	.globl _PT1
                                     57 	.globl _PX1
                                     58 	.globl _PT0
                                     59 	.globl _PX0
                                     60 	.globl _PD7
                                     61 	.globl _PD6
                                     62 	.globl _PD5
                                     63 	.globl _PD4
                                     64 	.globl _PD3
                                     65 	.globl _PD2
                                     66 	.globl _PD1
                                     67 	.globl _PD0
                                     68 	.globl _EA
                                     69 	.globl _ES1
                                     70 	.globl _ET2
                                     71 	.globl _ES0
                                     72 	.globl _ET1
                                     73 	.globl _EX1
                                     74 	.globl _ET0
                                     75 	.globl _EX0
                                     76 	.globl _PC7
                                     77 	.globl _PC6
                                     78 	.globl _PC5
                                     79 	.globl _PC4
                                     80 	.globl _PC3
                                     81 	.globl _PC2
                                     82 	.globl _PC1
                                     83 	.globl _PC0
                                     84 	.globl _SM0
                                     85 	.globl _SM1
                                     86 	.globl _SM2
                                     87 	.globl _REN
                                     88 	.globl _TB8
                                     89 	.globl _RB8
                                     90 	.globl _TI
                                     91 	.globl _RI
                                     92 	.globl _PB7
                                     93 	.globl _PB6
                                     94 	.globl _PB5
                                     95 	.globl _PB4
                                     96 	.globl _PB3
                                     97 	.globl _PB2
                                     98 	.globl _PB1
                                     99 	.globl _PB0
                                    100 	.globl _TF1
                                    101 	.globl _TR1
                                    102 	.globl _TF0
                                    103 	.globl _TR0
                                    104 	.globl _IE1
                                    105 	.globl _IT1
                                    106 	.globl _IE0
                                    107 	.globl _IT0
                                    108 	.globl _PA7
                                    109 	.globl _PA6
                                    110 	.globl _PA5
                                    111 	.globl _PA4
                                    112 	.globl _PA3
                                    113 	.globl _PA2
                                    114 	.globl _PA1
                                    115 	.globl _PA0
                                    116 	.globl _EIP
                                    117 	.globl _B
                                    118 	.globl _EIE
                                    119 	.globl _ACC
                                    120 	.globl _EICON
                                    121 	.globl _PSW
                                    122 	.globl _TH2
                                    123 	.globl _TL2
                                    124 	.globl _RCAP2H
                                    125 	.globl _RCAP2L
                                    126 	.globl _T2CON
                                    127 	.globl _SBUF1
                                    128 	.globl _SCON1
                                    129 	.globl _GPIFSGLDATLNOX
                                    130 	.globl _GPIFSGLDATLX
                                    131 	.globl _GPIFSGLDATH
                                    132 	.globl _GPIFTRIG
                                    133 	.globl _EP01STAT
                                    134 	.globl _IP
                                    135 	.globl _OEE
                                    136 	.globl _OED
                                    137 	.globl _OEC
                                    138 	.globl _OEB
                                    139 	.globl _OEA
                                    140 	.globl _IOE
                                    141 	.globl _IOD
                                    142 	.globl _AUTOPTRSETUP
                                    143 	.globl _EP68FIFOFLGS
                                    144 	.globl _EP24FIFOFLGS
                                    145 	.globl _EP2468STAT
                                    146 	.globl _IE
                                    147 	.globl _INT4CLR
                                    148 	.globl _INT2CLR
                                    149 	.globl _IOC
                                    150 	.globl _AUTOPTRL2
                                    151 	.globl _AUTOPTRH2
                                    152 	.globl _AUTOPTRL1
                                    153 	.globl _AUTOPTRH1
                                    154 	.globl _SBUF0
                                    155 	.globl _SCON0
                                    156 	.globl _MPAGE
                                    157 	.globl _EXIF
                                    158 	.globl _IOB
                                    159 	.globl _CKCON
                                    160 	.globl _TH1
                                    161 	.globl _TH0
                                    162 	.globl _TL1
                                    163 	.globl _TL0
                                    164 	.globl _TMOD
                                    165 	.globl _TCON
                                    166 	.globl _PCON
                                    167 	.globl _DPS
                                    168 	.globl _DPH1
                                    169 	.globl _DPL1
                                    170 	.globl _DPH
                                    171 	.globl _DPL
                                    172 	.globl _SP
                                    173 	.globl _IOA
                                    174 	.globl _EP8FIFOBUF
                                    175 	.globl _EP6FIFOBUF
                                    176 	.globl _EP4FIFOBUF
                                    177 	.globl _EP2FIFOBUF
                                    178 	.globl _EP1INBUF
                                    179 	.globl _EP1OUTBUF
                                    180 	.globl _EP0BUF
                                    181 	.globl _GPIFABORT
                                    182 	.globl _GPIFREADYSTAT
                                    183 	.globl _GPIFREADYCFG
                                    184 	.globl _XGPIFSGLDATLNOX
                                    185 	.globl _XGPIFSGLDATLX
                                    186 	.globl _XGPIFSGLDATH
                                    187 	.globl _EP8GPIFTRIG
                                    188 	.globl _EP8GPIFPFSTOP
                                    189 	.globl _EP8GPIFFLGSEL
                                    190 	.globl _EP6GPIFTRIG
                                    191 	.globl _EP6GPIFPFSTOP
                                    192 	.globl _EP6GPIFFLGSEL
                                    193 	.globl _EP4GPIFTRIG
                                    194 	.globl _EP4GPIFPFSTOP
                                    195 	.globl _EP4GPIFFLGSEL
                                    196 	.globl _EP2GPIFTRIG
                                    197 	.globl _EP2GPIFPFSTOP
                                    198 	.globl _EP2GPIFFLGSEL
                                    199 	.globl _GPIFTCB0
                                    200 	.globl _GPIFTCB1
                                    201 	.globl _GPIFTCB2
                                    202 	.globl _GPIFTCB3
                                    203 	.globl _FLOWSTBHPERIOD
                                    204 	.globl _FLOWSTBEDGE
                                    205 	.globl _FLOWSTB
                                    206 	.globl _FLOWHOLDOFF
                                    207 	.globl _FLOWEQ1CTL
                                    208 	.globl _FLOWEQ0CTL
                                    209 	.globl _FLOWLOGIC
                                    210 	.globl _FLOWSTATE
                                    211 	.globl _GPIFADRL
                                    212 	.globl _GPIFADRH
                                    213 	.globl _GPIFCTLCFG
                                    214 	.globl _GPIFIDLECTL
                                    215 	.globl _GPIFIDLECS
                                    216 	.globl _GPIFWFSELECT
                                    217 	.globl _SETUPDAT
                                    218 	.globl _SUDPTRCTL
                                    219 	.globl _SUDPTRL
                                    220 	.globl _SUDPTRH
                                    221 	.globl _EP8FIFOBCL
                                    222 	.globl _EP8FIFOBCH
                                    223 	.globl _EP6FIFOBCL
                                    224 	.globl _EP6FIFOBCH
                                    225 	.globl _EP4FIFOBCL
                                    226 	.globl _EP4FIFOBCH
                                    227 	.globl _EP2FIFOBCL
                                    228 	.globl _EP2FIFOBCH
                                    229 	.globl _EP8FIFOFLGS
                                    230 	.globl _EP6FIFOFLGS
                                    231 	.globl _EP4FIFOFLGS
                                    232 	.globl _EP2FIFOFLGS
                                    233 	.globl _EP8CS
                                    234 	.globl _EP6CS
                                    235 	.globl _EP4CS
                                    236 	.globl _EP2CS
                                    237 	.globl _EP1INCS
                                    238 	.globl _EP1OUTCS
                                    239 	.globl _EP0CS
                                    240 	.globl _EP8BCL
                                    241 	.globl _EP8BCH
                                    242 	.globl _EP6BCL
                                    243 	.globl _EP6BCH
                                    244 	.globl _EP4BCL
                                    245 	.globl _EP4BCH
                                    246 	.globl _EP2BCL
                                    247 	.globl _EP2BCH
                                    248 	.globl _EP1INBC
                                    249 	.globl _EP1OUTBC
                                    250 	.globl _EP0BCL
                                    251 	.globl _EP0BCH
                                    252 	.globl _FNADDR
                                    253 	.globl _MICROFRAME
                                    254 	.globl _USBFRAMEL
                                    255 	.globl _USBFRAMEH
                                    256 	.globl _TOGCTL
                                    257 	.globl _WAKEUPCS
                                    258 	.globl _SUSPEND
                                    259 	.globl _USBCS
                                    260 	.globl _UDMACRCQUAL
                                    261 	.globl _UDMACRCL
                                    262 	.globl _UDMACRCH
                                    263 	.globl _XAUTODAT2
                                    264 	.globl _XAUTODAT1
                                    265 	.globl _I2CTL
                                    266 	.globl _I2DAT
                                    267 	.globl _I2CS
                                    268 	.globl _PORTECFG
                                    269 	.globl _PORTCCFG
                                    270 	.globl _PORTACFG
                                    271 	.globl _INTSETUP
                                    272 	.globl _INT4IVEC
                                    273 	.globl _INT2IVEC
                                    274 	.globl _CLRERRCNT
                                    275 	.globl _ERRCNTLIM
                                    276 	.globl _USBERRIRQ
                                    277 	.globl _USBERRIE
                                    278 	.globl _GPIFIRQ
                                    279 	.globl _GPIFIE
                                    280 	.globl _EPIRQ
                                    281 	.globl _EPIE
                                    282 	.globl _USBIRQ
                                    283 	.globl _USBIE
                                    284 	.globl _NAKIRQ
                                    285 	.globl _NAKIE
                                    286 	.globl _IBNIRQ
                                    287 	.globl _IBNIE
                                    288 	.globl _EP8FIFOIRQ
                                    289 	.globl _EP8FIFOIE
                                    290 	.globl _EP6FIFOIRQ
                                    291 	.globl _EP6FIFOIE
                                    292 	.globl _EP4FIFOIRQ
                                    293 	.globl _EP4FIFOIE
                                    294 	.globl _EP2FIFOIRQ
                                    295 	.globl _EP2FIFOIE
                                    296 	.globl _OUTPKTEND
                                    297 	.globl _INPKTEND
                                    298 	.globl _EP8ISOINPKTS
                                    299 	.globl _EP6ISOINPKTS
                                    300 	.globl _EP4ISOINPKTS
                                    301 	.globl _EP2ISOINPKTS
                                    302 	.globl _EP8FIFOPFL
                                    303 	.globl _EP8FIFOPFH
                                    304 	.globl _EP6FIFOPFL
                                    305 	.globl _EP6FIFOPFH
                                    306 	.globl _EP4FIFOPFL
                                    307 	.globl _EP4FIFOPFH
                                    308 	.globl _EP2FIFOPFL
                                    309 	.globl _EP2FIFOPFH
                                    310 	.globl _ECC2B2
                                    311 	.globl _ECC2B1
                                    312 	.globl _ECC2B0
                                    313 	.globl _ECC1B2
                                    314 	.globl _ECC1B1
                                    315 	.globl _ECC1B0
                                    316 	.globl _ECCRESET
                                    317 	.globl _ECCCFG
                                    318 	.globl _EP8AUTOINLENL
                                    319 	.globl _EP8AUTOINLENH
                                    320 	.globl _EP6AUTOINLENL
                                    321 	.globl _EP6AUTOINLENH
                                    322 	.globl _EP4AUTOINLENL
                                    323 	.globl _EP4AUTOINLENH
                                    324 	.globl _EP2AUTOINLENL
                                    325 	.globl _EP2AUTOINLENH
                                    326 	.globl _EP8FIFOCFG
                                    327 	.globl _EP6FIFOCFG
                                    328 	.globl _EP4FIFOCFG
                                    329 	.globl _EP2FIFOCFG
                                    330 	.globl _EP8CFG
                                    331 	.globl _EP6CFG
                                    332 	.globl _EP4CFG
                                    333 	.globl _EP2CFG
                                    334 	.globl _EP1INCFG
                                    335 	.globl _EP1OUTCFG
                                    336 	.globl _GPIFHOLDAMOUNT
                                    337 	.globl _REVCTL
                                    338 	.globl _REVID
                                    339 	.globl _FIFOPINPOLAR
                                    340 	.globl _UART230
                                    341 	.globl _BPADDRL
                                    342 	.globl _BPADDRH
                                    343 	.globl _BREAKPT
                                    344 	.globl _FIFORESET
                                    345 	.globl _PINFLAGSCD
                                    346 	.globl _PINFLAGSAB
                                    347 	.globl _IFCONFIG
                                    348 	.globl _CPUCS
                                    349 	.globl _WAVEDATA
                                    350 ;--------------------------------------------------------
                                    351 ; special function registers
                                    352 ;--------------------------------------------------------
                                    353 	.area RSEG    (ABS,DATA)
      000000                        354 	.org 0x0000
                           000080   355 _IOA	=	0x0080
                           000081   356 _SP	=	0x0081
                           000082   357 _DPL	=	0x0082
                           000083   358 _DPH	=	0x0083
                           000084   359 _DPL1	=	0x0084
                           000085   360 _DPH1	=	0x0085
                           000086   361 _DPS	=	0x0086
                           000087   362 _PCON	=	0x0087
                           000088   363 _TCON	=	0x0088
                           000089   364 _TMOD	=	0x0089
                           00008A   365 _TL0	=	0x008a
                           00008B   366 _TL1	=	0x008b
                           00008C   367 _TH0	=	0x008c
                           00008D   368 _TH1	=	0x008d
                           00008E   369 _CKCON	=	0x008e
                           000090   370 _IOB	=	0x0090
                           000091   371 _EXIF	=	0x0091
                           000092   372 _MPAGE	=	0x0092
                           000098   373 _SCON0	=	0x0098
                           000099   374 _SBUF0	=	0x0099
                           00009A   375 _AUTOPTRH1	=	0x009a
                           00009B   376 _AUTOPTRL1	=	0x009b
                           00009D   377 _AUTOPTRH2	=	0x009d
                           00009E   378 _AUTOPTRL2	=	0x009e
                           0000A0   379 _IOC	=	0x00a0
                           0000A1   380 _INT2CLR	=	0x00a1
                           0000A2   381 _INT4CLR	=	0x00a2
                           0000A8   382 _IE	=	0x00a8
                           0000AA   383 _EP2468STAT	=	0x00aa
                           0000AB   384 _EP24FIFOFLGS	=	0x00ab
                           0000AC   385 _EP68FIFOFLGS	=	0x00ac
                           0000AF   386 _AUTOPTRSETUP	=	0x00af
                           0000B0   387 _IOD	=	0x00b0
                           0000B1   388 _IOE	=	0x00b1
                           0000B2   389 _OEA	=	0x00b2
                           0000B3   390 _OEB	=	0x00b3
                           0000B4   391 _OEC	=	0x00b4
                           0000B5   392 _OED	=	0x00b5
                           0000B6   393 _OEE	=	0x00b6
                           0000B8   394 _IP	=	0x00b8
                           0000BA   395 _EP01STAT	=	0x00ba
                           0000BB   396 _GPIFTRIG	=	0x00bb
                           0000BD   397 _GPIFSGLDATH	=	0x00bd
                           0000BE   398 _GPIFSGLDATLX	=	0x00be
                           0000BF   399 _GPIFSGLDATLNOX	=	0x00bf
                           0000C0   400 _SCON1	=	0x00c0
                           0000C1   401 _SBUF1	=	0x00c1
                           0000C8   402 _T2CON	=	0x00c8
                           0000CA   403 _RCAP2L	=	0x00ca
                           0000CB   404 _RCAP2H	=	0x00cb
                           0000CC   405 _TL2	=	0x00cc
                           0000CD   406 _TH2	=	0x00cd
                           0000D0   407 _PSW	=	0x00d0
                           0000D8   408 _EICON	=	0x00d8
                           0000E0   409 _ACC	=	0x00e0
                           0000E8   410 _EIE	=	0x00e8
                           0000F0   411 _B	=	0x00f0
                           0000F8   412 _EIP	=	0x00f8
                                    413 ;--------------------------------------------------------
                                    414 ; special function bits
                                    415 ;--------------------------------------------------------
                                    416 	.area RSEG    (ABS,DATA)
      000000                        417 	.org 0x0000
                           000080   418 _PA0	=	0x0080
                           000081   419 _PA1	=	0x0081
                           000082   420 _PA2	=	0x0082
                           000083   421 _PA3	=	0x0083
                           000084   422 _PA4	=	0x0084
                           000085   423 _PA5	=	0x0085
                           000086   424 _PA6	=	0x0086
                           000087   425 _PA7	=	0x0087
                           000088   426 _IT0	=	0x0088
                           000089   427 _IE0	=	0x0089
                           00008A   428 _IT1	=	0x008a
                           00008B   429 _IE1	=	0x008b
                           00008C   430 _TR0	=	0x008c
                           00008D   431 _TF0	=	0x008d
                           00008E   432 _TR1	=	0x008e
                           00008F   433 _TF1	=	0x008f
                           000090   434 _PB0	=	0x0090
                           000091   435 _PB1	=	0x0091
                           000092   436 _PB2	=	0x0092
                           000093   437 _PB3	=	0x0093
                           000094   438 _PB4	=	0x0094
                           000095   439 _PB5	=	0x0095
                           000096   440 _PB6	=	0x0096
                           000097   441 _PB7	=	0x0097
                           000098   442 _RI	=	0x0098
                           000099   443 _TI	=	0x0099
                           00009A   444 _RB8	=	0x009a
                           00009B   445 _TB8	=	0x009b
                           00009C   446 _REN	=	0x009c
                           00009D   447 _SM2	=	0x009d
                           00009E   448 _SM1	=	0x009e
                           00009F   449 _SM0	=	0x009f
                           0000A0   450 _PC0	=	0x00a0
                           0000A1   451 _PC1	=	0x00a1
                           0000A2   452 _PC2	=	0x00a2
                           0000A3   453 _PC3	=	0x00a3
                           0000A4   454 _PC4	=	0x00a4
                           0000A5   455 _PC5	=	0x00a5
                           0000A6   456 _PC6	=	0x00a6
                           0000A7   457 _PC7	=	0x00a7
                           0000A8   458 _EX0	=	0x00a8
                           0000A9   459 _ET0	=	0x00a9
                           0000AA   460 _EX1	=	0x00aa
                           0000AB   461 _ET1	=	0x00ab
                           0000AC   462 _ES0	=	0x00ac
                           0000AD   463 _ET2	=	0x00ad
                           0000AE   464 _ES1	=	0x00ae
                           0000AF   465 _EA	=	0x00af
                           0000B0   466 _PD0	=	0x00b0
                           0000B1   467 _PD1	=	0x00b1
                           0000B2   468 _PD2	=	0x00b2
                           0000B3   469 _PD3	=	0x00b3
                           0000B4   470 _PD4	=	0x00b4
                           0000B5   471 _PD5	=	0x00b5
                           0000B6   472 _PD6	=	0x00b6
                           0000B7   473 _PD7	=	0x00b7
                           0000B8   474 _PX0	=	0x00b8
                           0000B9   475 _PT0	=	0x00b9
                           0000BA   476 _PX1	=	0x00ba
                           0000BB   477 _PT1	=	0x00bb
                           0000BC   478 _PS0	=	0x00bc
                           0000BD   479 _PT2	=	0x00bd
                           0000BE   480 _PS1	=	0x00be
                           0000C0   481 _RI1	=	0x00c0
                           0000C1   482 _TI1	=	0x00c1
                           0000C2   483 _RB81	=	0x00c2
                           0000C3   484 _TB81	=	0x00c3
                           0000C4   485 _REN1	=	0x00c4
                           0000C5   486 _SM21	=	0x00c5
                           0000C6   487 _SM11	=	0x00c6
                           0000C7   488 _SM01	=	0x00c7
                           0000C8   489 _CP_RL2	=	0x00c8
                           0000C9   490 _C_T2	=	0x00c9
                           0000CA   491 _TR2	=	0x00ca
                           0000CB   492 _EXEN2	=	0x00cb
                           0000CC   493 _TCLK	=	0x00cc
                           0000CD   494 _RCLK	=	0x00cd
                           0000CE   495 _EXF2	=	0x00ce
                           0000CF   496 _TF2	=	0x00cf
                           0000D0   497 _P	=	0x00d0
                           0000D1   498 _FL	=	0x00d1
                           0000D2   499 _OV	=	0x00d2
                           0000D3   500 _RS0	=	0x00d3
                           0000D4   501 _RS1	=	0x00d4
                           0000D5   502 _F0	=	0x00d5
                           0000D6   503 _AC	=	0x00d6
                           0000D7   504 _CY	=	0x00d7
                           0000DB   505 _INT6	=	0x00db
                           0000DC   506 _RESI	=	0x00dc
                           0000DD   507 _ERESI	=	0x00dd
                           0000DF   508 _SMOD1	=	0x00df
                           0000E8   509 _EUSB	=	0x00e8
                           0000E9   510 _EI2C	=	0x00e9
                           0000EA   511 _EIEX4	=	0x00ea
                           0000EB   512 _EIEX5	=	0x00eb
                           0000EC   513 _EIEX6	=	0x00ec
                           0000F8   514 _PUSB	=	0x00f8
                           0000F9   515 _PI2C	=	0x00f9
                           0000FA   516 _EIPX4	=	0x00fa
                           0000FB   517 _EIPX5	=	0x00fb
                           0000FC   518 _EIPX6	=	0x00fc
                                    519 ;--------------------------------------------------------
                                    520 ; overlayable register banks
                                    521 ;--------------------------------------------------------
                                    522 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        523 	.ds 8
                                    524 ;--------------------------------------------------------
                                    525 ; overlayable bit register bank
                                    526 ;--------------------------------------------------------
                                    527 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        528 bits:
      000020                        529 	.ds 1
                           008000   530 	b0 = bits[0]
                           008100   531 	b1 = bits[1]
                           008200   532 	b2 = bits[2]
                           008300   533 	b3 = bits[3]
                           008400   534 	b4 = bits[4]
                           008500   535 	b5 = bits[5]
                           008600   536 	b6 = bits[6]
                           008700   537 	b7 = bits[7]
                                    538 ;--------------------------------------------------------
                                    539 ; internal ram data
                                    540 ;--------------------------------------------------------
                                    541 	.area DSEG    (DATA)
      000008                        542 _x1:
      000008                        543 	.ds 1
      000009                        544 _x2:
      000009                        545 	.ds 1
      00000A                        546 _x3:
      00000A                        547 	.ds 1
      00000B                        548 _xA:
      00000B                        549 	.ds 1
      00000C                        550 _x4:
      00000C                        551 	.ds 1
      00000D                        552 _x5:
      00000D                        553 	.ds 1
      00000E                        554 _x6:
      00000E                        555 	.ds 1
      00000F                        556 _xB:
      00000F                        557 	.ds 1
      000010                        558 _x7:
      000010                        559 	.ds 1
      000011                        560 _x8:
      000011                        561 	.ds 1
      000012                        562 _x9:
      000012                        563 	.ds 1
      000013                        564 _xC:
      000013                        565 	.ds 1
      000014                        566 _xK:
      000014                        567 	.ds 1
      000015                        568 _x0:
      000015                        569 	.ds 1
      000016                        570 _xS:
      000016                        571 	.ds 1
      000017                        572 _xD:
      000017                        573 	.ds 1
      000018                        574 _p_any:
      000018                        575 	.ds 1
                                    576 ;--------------------------------------------------------
                                    577 ; overlayable items in internal ram
                                    578 ;--------------------------------------------------------
                                    579 ;--------------------------------------------------------
                                    580 ; Stack segment in internal ram
                                    581 ;--------------------------------------------------------
                                    582 	.area SSEG
      000021                        583 __start__stack:
      000021                        584 	.ds	1
                                    585 
                                    586 ;--------------------------------------------------------
                                    587 ; indirectly addressable internal ram data
                                    588 ;--------------------------------------------------------
                                    589 	.area ISEG    (DATA)
                                    590 ;--------------------------------------------------------
                                    591 ; absolute internal ram data
                                    592 ;--------------------------------------------------------
                                    593 	.area IABS    (ABS,DATA)
                                    594 	.area IABS    (ABS,DATA)
                                    595 ;--------------------------------------------------------
                                    596 ; bit data
                                    597 ;--------------------------------------------------------
                                    598 	.area BSEG    (BIT)
                                    599 ;--------------------------------------------------------
                                    600 ; paged external ram data
                                    601 ;--------------------------------------------------------
                                    602 	.area PSEG    (PAG,XDATA)
                                    603 ;--------------------------------------------------------
                                    604 ; uninitialized external ram data
                                    605 ;--------------------------------------------------------
                                    606 	.area XSEG    (XDATA)
                           00E400   607 _WAVEDATA	=	0xe400
                           00E600   608 _CPUCS	=	0xe600
                           00E601   609 _IFCONFIG	=	0xe601
                           00E602   610 _PINFLAGSAB	=	0xe602
                           00E603   611 _PINFLAGSCD	=	0xe603
                           00E604   612 _FIFORESET	=	0xe604
                           00E605   613 _BREAKPT	=	0xe605
                           00E606   614 _BPADDRH	=	0xe606
                           00E607   615 _BPADDRL	=	0xe607
                           00E608   616 _UART230	=	0xe608
                           00E609   617 _FIFOPINPOLAR	=	0xe609
                           00E60A   618 _REVID	=	0xe60a
                           00E60B   619 _REVCTL	=	0xe60b
                           00E60C   620 _GPIFHOLDAMOUNT	=	0xe60c
                           00E610   621 _EP1OUTCFG	=	0xe610
                           00E611   622 _EP1INCFG	=	0xe611
                           00E612   623 _EP2CFG	=	0xe612
                           00E613   624 _EP4CFG	=	0xe613
                           00E614   625 _EP6CFG	=	0xe614
                           00E615   626 _EP8CFG	=	0xe615
                           00E618   627 _EP2FIFOCFG	=	0xe618
                           00E619   628 _EP4FIFOCFG	=	0xe619
                           00E61A   629 _EP6FIFOCFG	=	0xe61a
                           00E61B   630 _EP8FIFOCFG	=	0xe61b
                           00E620   631 _EP2AUTOINLENH	=	0xe620
                           00E621   632 _EP2AUTOINLENL	=	0xe621
                           00E622   633 _EP4AUTOINLENH	=	0xe622
                           00E623   634 _EP4AUTOINLENL	=	0xe623
                           00E624   635 _EP6AUTOINLENH	=	0xe624
                           00E625   636 _EP6AUTOINLENL	=	0xe625
                           00E626   637 _EP8AUTOINLENH	=	0xe626
                           00E627   638 _EP8AUTOINLENL	=	0xe627
                           00E628   639 _ECCCFG	=	0xe628
                           00E629   640 _ECCRESET	=	0xe629
                           00E62A   641 _ECC1B0	=	0xe62a
                           00E62B   642 _ECC1B1	=	0xe62b
                           00E62C   643 _ECC1B2	=	0xe62c
                           00E62D   644 _ECC2B0	=	0xe62d
                           00E62E   645 _ECC2B1	=	0xe62e
                           00E62F   646 _ECC2B2	=	0xe62f
                           00E630   647 _EP2FIFOPFH	=	0xe630
                           00E631   648 _EP2FIFOPFL	=	0xe631
                           00E632   649 _EP4FIFOPFH	=	0xe632
                           00E633   650 _EP4FIFOPFL	=	0xe633
                           00E634   651 _EP6FIFOPFH	=	0xe634
                           00E635   652 _EP6FIFOPFL	=	0xe635
                           00E636   653 _EP8FIFOPFH	=	0xe636
                           00E637   654 _EP8FIFOPFL	=	0xe637
                           00E640   655 _EP2ISOINPKTS	=	0xe640
                           00E641   656 _EP4ISOINPKTS	=	0xe641
                           00E642   657 _EP6ISOINPKTS	=	0xe642
                           00E643   658 _EP8ISOINPKTS	=	0xe643
                           00E648   659 _INPKTEND	=	0xe648
                           00E649   660 _OUTPKTEND	=	0xe649
                           00E650   661 _EP2FIFOIE	=	0xe650
                           00E651   662 _EP2FIFOIRQ	=	0xe651
                           00E652   663 _EP4FIFOIE	=	0xe652
                           00E653   664 _EP4FIFOIRQ	=	0xe653
                           00E654   665 _EP6FIFOIE	=	0xe654
                           00E655   666 _EP6FIFOIRQ	=	0xe655
                           00E656   667 _EP8FIFOIE	=	0xe656
                           00E657   668 _EP8FIFOIRQ	=	0xe657
                           00E658   669 _IBNIE	=	0xe658
                           00E659   670 _IBNIRQ	=	0xe659
                           00E65A   671 _NAKIE	=	0xe65a
                           00E65B   672 _NAKIRQ	=	0xe65b
                           00E65C   673 _USBIE	=	0xe65c
                           00E65D   674 _USBIRQ	=	0xe65d
                           00E65E   675 _EPIE	=	0xe65e
                           00E65F   676 _EPIRQ	=	0xe65f
                           00E660   677 _GPIFIE	=	0xe660
                           00E661   678 _GPIFIRQ	=	0xe661
                           00E662   679 _USBERRIE	=	0xe662
                           00E663   680 _USBERRIRQ	=	0xe663
                           00E664   681 _ERRCNTLIM	=	0xe664
                           00E665   682 _CLRERRCNT	=	0xe665
                           00E666   683 _INT2IVEC	=	0xe666
                           00E667   684 _INT4IVEC	=	0xe667
                           00E668   685 _INTSETUP	=	0xe668
                           00E670   686 _PORTACFG	=	0xe670
                           00E671   687 _PORTCCFG	=	0xe671
                           00E672   688 _PORTECFG	=	0xe672
                           00E678   689 _I2CS	=	0xe678
                           00E679   690 _I2DAT	=	0xe679
                           00E67A   691 _I2CTL	=	0xe67a
                           00E67B   692 _XAUTODAT1	=	0xe67b
                           00E67C   693 _XAUTODAT2	=	0xe67c
                           00E67D   694 _UDMACRCH	=	0xe67d
                           00E67E   695 _UDMACRCL	=	0xe67e
                           00E67F   696 _UDMACRCQUAL	=	0xe67f
                           00E680   697 _USBCS	=	0xe680
                           00E681   698 _SUSPEND	=	0xe681
                           00E682   699 _WAKEUPCS	=	0xe682
                           00E683   700 _TOGCTL	=	0xe683
                           00E684   701 _USBFRAMEH	=	0xe684
                           00E685   702 _USBFRAMEL	=	0xe685
                           00E686   703 _MICROFRAME	=	0xe686
                           00E687   704 _FNADDR	=	0xe687
                           00E68A   705 _EP0BCH	=	0xe68a
                           00E68B   706 _EP0BCL	=	0xe68b
                           00E68D   707 _EP1OUTBC	=	0xe68d
                           00E68F   708 _EP1INBC	=	0xe68f
                           00E690   709 _EP2BCH	=	0xe690
                           00E691   710 _EP2BCL	=	0xe691
                           00E694   711 _EP4BCH	=	0xe694
                           00E695   712 _EP4BCL	=	0xe695
                           00E698   713 _EP6BCH	=	0xe698
                           00E699   714 _EP6BCL	=	0xe699
                           00E69C   715 _EP8BCH	=	0xe69c
                           00E69D   716 _EP8BCL	=	0xe69d
                           00E6A0   717 _EP0CS	=	0xe6a0
                           00E6A1   718 _EP1OUTCS	=	0xe6a1
                           00E6A2   719 _EP1INCS	=	0xe6a2
                           00E6A3   720 _EP2CS	=	0xe6a3
                           00E6A4   721 _EP4CS	=	0xe6a4
                           00E6A5   722 _EP6CS	=	0xe6a5
                           00E6A6   723 _EP8CS	=	0xe6a6
                           00E6A7   724 _EP2FIFOFLGS	=	0xe6a7
                           00E6A8   725 _EP4FIFOFLGS	=	0xe6a8
                           00E6A9   726 _EP6FIFOFLGS	=	0xe6a9
                           00E6AA   727 _EP8FIFOFLGS	=	0xe6aa
                           00E6AB   728 _EP2FIFOBCH	=	0xe6ab
                           00E6AC   729 _EP2FIFOBCL	=	0xe6ac
                           00E6AD   730 _EP4FIFOBCH	=	0xe6ad
                           00E6AE   731 _EP4FIFOBCL	=	0xe6ae
                           00E6AF   732 _EP6FIFOBCH	=	0xe6af
                           00E6B0   733 _EP6FIFOBCL	=	0xe6b0
                           00E6B1   734 _EP8FIFOBCH	=	0xe6b1
                           00E6B2   735 _EP8FIFOBCL	=	0xe6b2
                           00E6B3   736 _SUDPTRH	=	0xe6b3
                           00E6B4   737 _SUDPTRL	=	0xe6b4
                           00E6B5   738 _SUDPTRCTL	=	0xe6b5
                           00E6B8   739 _SETUPDAT	=	0xe6b8
                           00E6C0   740 _GPIFWFSELECT	=	0xe6c0
                           00E6C1   741 _GPIFIDLECS	=	0xe6c1
                           00E6C2   742 _GPIFIDLECTL	=	0xe6c2
                           00E6C3   743 _GPIFCTLCFG	=	0xe6c3
                           00E6C4   744 _GPIFADRH	=	0xe6c4
                           00E6C5   745 _GPIFADRL	=	0xe6c5
                           00E6C6   746 _FLOWSTATE	=	0xe6c6
                           00E6C7   747 _FLOWLOGIC	=	0xe6c7
                           00E6C8   748 _FLOWEQ0CTL	=	0xe6c8
                           00E6C9   749 _FLOWEQ1CTL	=	0xe6c9
                           00E6CA   750 _FLOWHOLDOFF	=	0xe6ca
                           00E6CB   751 _FLOWSTB	=	0xe6cb
                           00E6CC   752 _FLOWSTBEDGE	=	0xe6cc
                           00E6CD   753 _FLOWSTBHPERIOD	=	0xe6cd
                           00E6CE   754 _GPIFTCB3	=	0xe6ce
                           00E6CF   755 _GPIFTCB2	=	0xe6cf
                           00E6D0   756 _GPIFTCB1	=	0xe6d0
                           00E6D1   757 _GPIFTCB0	=	0xe6d1
                           00E6D2   758 _EP2GPIFFLGSEL	=	0xe6d2
                           00E6D3   759 _EP2GPIFPFSTOP	=	0xe6d3
                           00E6D4   760 _EP2GPIFTRIG	=	0xe6d4
                           00E6DA   761 _EP4GPIFFLGSEL	=	0xe6da
                           00E6DB   762 _EP4GPIFPFSTOP	=	0xe6db
                           00E6DC   763 _EP4GPIFTRIG	=	0xe6dc
                           00E6E2   764 _EP6GPIFFLGSEL	=	0xe6e2
                           00E6E3   765 _EP6GPIFPFSTOP	=	0xe6e3
                           00E6E4   766 _EP6GPIFTRIG	=	0xe6e4
                           00E6EA   767 _EP8GPIFFLGSEL	=	0xe6ea
                           00E6EB   768 _EP8GPIFPFSTOP	=	0xe6eb
                           00E6EC   769 _EP8GPIFTRIG	=	0xe6ec
                           00E6F0   770 _XGPIFSGLDATH	=	0xe6f0
                           00E6F1   771 _XGPIFSGLDATLX	=	0xe6f1
                           00E6F2   772 _XGPIFSGLDATLNOX	=	0xe6f2
                           00E6F3   773 _GPIFREADYCFG	=	0xe6f3
                           00E6F4   774 _GPIFREADYSTAT	=	0xe6f4
                           00E6F5   775 _GPIFABORT	=	0xe6f5
                           00E740   776 _EP0BUF	=	0xe740
                           00E780   777 _EP1OUTBUF	=	0xe780
                           00E7C0   778 _EP1INBUF	=	0xe7c0
                           00F000   779 _EP2FIFOBUF	=	0xf000
                           00F400   780 _EP4FIFOBUF	=	0xf400
                           00F800   781 _EP6FIFOBUF	=	0xf800
                           00FC00   782 _EP8FIFOBUF	=	0xfc00
                                    783 ;--------------------------------------------------------
                                    784 ; absolute external ram data
                                    785 ;--------------------------------------------------------
                                    786 	.area XABS    (ABS,XDATA)
                                    787 ;--------------------------------------------------------
                                    788 ; initialized external ram data
                                    789 ;--------------------------------------------------------
                                    790 	.area XISEG   (XDATA)
                                    791 	.area HOME    (CODE)
                                    792 	.area GSINIT0 (CODE)
                                    793 	.area GSINIT1 (CODE)
                                    794 	.area GSINIT2 (CODE)
                                    795 	.area GSINIT3 (CODE)
                                    796 	.area GSINIT4 (CODE)
                                    797 	.area GSINIT5 (CODE)
                                    798 	.area GSINIT  (CODE)
                                    799 	.area GSFINAL (CODE)
                                    800 	.area CSEG    (CODE)
                                    801 ;--------------------------------------------------------
                                    802 ; interrupt vector
                                    803 ;--------------------------------------------------------
                                    804 	.area HOME    (CODE)
      000000                        805 __interrupt_vect:
      000000 02 00 8C         [24]  806 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  807 	reti
      000004                        808 	.ds	7
      00000B 32               [24]  809 	reti
      00000C                        810 	.ds	7
      000013 32               [24]  811 	reti
      000014                        812 	.ds	7
      00001B 32               [24]  813 	reti
      00001C                        814 	.ds	7
      000023 32               [24]  815 	reti
      000024                        816 	.ds	7
      00002B 32               [24]  817 	reti
      00002C                        818 	.ds	7
      000033 32               [24]  819 	reti
      000034                        820 	.ds	7
      00003B 32               [24]  821 	reti
      00003C                        822 	.ds	7
      000043 02 04 B3         [24]  823 	ljmp	_isr
                                    824 ; restartable atomic support routines
      000046                        825 	.ds	2
      000048                        826 sdcc_atomic_exchange_rollback_start::
      000048 00               [12]  827 	nop
      000049 00               [12]  828 	nop
      00004A                        829 sdcc_atomic_exchange_pdata_impl:
      00004A E2               [24]  830 	movx	a, @r0
      00004B FB               [12]  831 	mov	r3, a
      00004C EA               [12]  832 	mov	a, r2
      00004D F2               [24]  833 	movx	@r0, a
      00004E 80 2C            [24]  834 	sjmp	sdcc_atomic_exchange_exit
      000050 00               [12]  835 	nop
      000051 00               [12]  836 	nop
      000052                        837 sdcc_atomic_exchange_xdata_impl:
      000052 E0               [24]  838 	movx	a, @dptr
      000053 FB               [12]  839 	mov	r3, a
      000054 EA               [12]  840 	mov	a, r2
      000055 F0               [24]  841 	movx	@dptr, a
      000056 80 24            [24]  842 	sjmp	sdcc_atomic_exchange_exit
      000058                        843 sdcc_atomic_compare_exchange_idata_impl:
      000058 E6               [12]  844 	mov	a, @r0
      000059 B5 02 02         [24]  845 	cjne	a, ar2, .+#5
      00005C EB               [12]  846 	mov	a, r3
      00005D F6               [12]  847 	mov	@r0, a
      00005E 22               [24]  848 	ret
      00005F 00               [12]  849 	nop
      000060                        850 sdcc_atomic_compare_exchange_pdata_impl:
      000060 E2               [24]  851 	movx	a, @r0
      000061 B5 02 02         [24]  852 	cjne	a, ar2, .+#5
      000064 EB               [12]  853 	mov	a, r3
      000065 F2               [24]  854 	movx	@r0, a
      000066 22               [24]  855 	ret
      000067 00               [12]  856 	nop
      000068                        857 sdcc_atomic_compare_exchange_xdata_impl:
      000068 E0               [24]  858 	movx	a, @dptr
      000069 B5 02 02         [24]  859 	cjne	a, ar2, .+#5
      00006C EB               [12]  860 	mov	a, r3
      00006D F0               [24]  861 	movx	@dptr, a
      00006E 22               [24]  862 	ret
      00006F                        863 sdcc_atomic_exchange_rollback_end::
                                    864 
      00006F                        865 sdcc_atomic_exchange_gptr_impl::
      00006F 30 F6 E0         [24]  866 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000072 A8 82            [24]  867 	mov	r0, dpl
      000074 20 F5 D3         [24]  868 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000077                        869 sdcc_atomic_exchange_idata_impl:
      000077 EA               [12]  870 	mov	a, r2
      000078 C6               [12]  871 	xch	a, @r0
      000079 F5 82            [12]  872 	mov	dpl, a
      00007B 22               [24]  873 	ret
      00007C                        874 sdcc_atomic_exchange_exit:
      00007C 8B 82            [24]  875 	mov	dpl, r3
      00007E 22               [24]  876 	ret
      00007F                        877 sdcc_atomic_compare_exchange_gptr_impl::
      00007F 30 F6 E6         [24]  878 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000082 A8 82            [24]  879 	mov	r0, dpl
      000084 20 F5 D9         [24]  880 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000087 80 CF            [24]  881 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    882 ;--------------------------------------------------------
                                    883 ; global & static initialisations
                                    884 ;--------------------------------------------------------
                                    885 	.area HOME    (CODE)
                                    886 	.area GSINIT  (CODE)
                                    887 	.area GSFINAL (CODE)
                                    888 	.area GSINIT  (CODE)
                                    889 	.globl __sdcc_gsinit_startup
                                    890 	.globl __sdcc_program_startup
                                    891 	.globl __start__stack
                                    892 	.globl __mcs51_genXINIT
                                    893 	.globl __mcs51_genXRAMCLEAR
                                    894 	.globl __mcs51_genRAMCLEAR
                                    895 	.area GSFINAL (CODE)
      0000E5 02 00 89         [24]  896 	ljmp	__sdcc_program_startup
                                    897 ;--------------------------------------------------------
                                    898 ; Home
                                    899 ;--------------------------------------------------------
                                    900 	.area HOME    (CODE)
                                    901 	.area HOME    (CODE)
      000089                        902 __sdcc_program_startup:
      000089 02 03 BC         [24]  903 	ljmp	_main
                                    904 ;	return from main will return to caller
                                    905 ;--------------------------------------------------------
                                    906 ; code
                                    907 ;--------------------------------------------------------
                                    908 	.area CSEG    (CODE)
                                    909 ;------------------------------------------------------------
                                    910 ;Allocation info for local variables in function 'msleep'
                                    911 ;------------------------------------------------------------
                                    912 ;msec          Allocated to registers 
                                    913 ;i             Allocated to registers r5 
                                    914 ;------------------------------------------------------------
                                    915 ;	main.c:22: void msleep(WORD msec) {
                                    916 ;	-----------------------------------------
                                    917 ;	 function msleep
                                    918 ;	-----------------------------------------
      0000E8                        919 _msleep:
                           000007   920 	ar7 = 0x07
                           000006   921 	ar6 = 0x06
                           000005   922 	ar5 = 0x05
                           000004   923 	ar4 = 0x04
                           000003   924 	ar3 = 0x03
                           000002   925 	ar2 = 0x02
                           000001   926 	ar1 = 0x01
                           000000   927 	ar0 = 0x00
      0000E8 AE 82            [24]  928 	mov	r6, dpl
      0000EA AF 83            [24]  929 	mov	r7, dph
                                    930 ;	main.c:23: while (msec--) for (long i = 0; i < 8; i++);
      0000EC                        931 00102$:
      0000EC 8E 04            [24]  932 	mov	ar4,r6
      0000EE 8F 05            [24]  933 	mov	ar5,r7
      0000F0 1E               [12]  934 	dec	r6
      0000F1 BE FF 01         [24]  935 	cjne	r6,#0xff,00135$
      0000F4 1F               [12]  936 	dec	r7
      0000F5                        937 00135$:
      0000F5 EC               [12]  938 	mov	a,r4
      0000F6 4D               [12]  939 	orl	a,r5
      0000F7 60 0A            [24]  940 	jz	00108$
      0000F9 7D 00            [12]  941 	mov	r5,#0x00
      0000FB                        942 00106$:
      0000FB BD 08 00         [24]  943 	cjne	r5,#0x08,00137$
      0000FE                        944 00137$:
      0000FE 50 EC            [24]  945 	jnc	00102$
      000100 0D               [12]  946 	inc	r5
      000101 80 F8            [24]  947 	sjmp	00106$
      000103                        948 00108$:
                                    949 ;	main.c:24: }
      000103 22               [24]  950 	ret
                                    951 ;------------------------------------------------------------
                                    952 ;Allocation info for local variables in function 'key_'
                                    953 ;------------------------------------------------------------
                                    954 ;k             Allocated to stack - _bp -3 +1 
                                    955 ;m             Allocated to registers r7 
                                    956 ;------------------------------------------------------------
                                    957 ;	main.c:26: void key_(BYTE m, BYTE k) {
                                    958 ;	-----------------------------------------
                                    959 ;	 function key_
                                    960 ;	-----------------------------------------
      000104                        961 _key_:
      000104 C0 1A            [24]  962 	push	_bp
      000106 85 81 1A         [24]  963 	mov	_bp,sp
      000109 AF 82            [24]  964 	mov	r7, dpl
                                    965 ;	main.c:27: EP1INBUF[0] = m;
      00010B 90 E7 C0         [24]  966 	mov	dptr,#_EP1INBUF
      00010E EF               [12]  967 	mov	a,r7
      00010F F0               [24]  968 	movx	@dptr,a
                                    969 ;	main.c:28: EP1INBUF[1] = 0;
      000110 90 E7 C1         [24]  970 	mov	dptr,#(_EP1INBUF + 0x0001)
      000113 E4               [12]  971 	clr	a
      000114 F0               [24]  972 	movx	@dptr,a
                                    973 ;	main.c:29: EP1INBUF[2] = k;
      000115 90 E7 C2         [24]  974 	mov	dptr,#(_EP1INBUF + 0x0002)
      000118 E5 1A            [12]  975 	mov	a,_bp
      00011A 24 FD            [12]  976 	add	a,#0xfd
      00011C F8               [12]  977 	mov	r0,a
      00011D E6               [12]  978 	mov	a,@r0
      00011E F0               [24]  979 	movx	@dptr,a
                                    980 ;	main.c:30: EP1INBUF[3] = 0;
      00011F 90 E7 C3         [24]  981 	mov	dptr,#(_EP1INBUF + 0x0003)
      000122 E4               [12]  982 	clr	a
      000123 F0               [24]  983 	movx	@dptr,a
                                    984 ;	main.c:31: EP1INBUF[4] = 0;
      000124 90 E7 C4         [24]  985 	mov	dptr,#(_EP1INBUF + 0x0004)
      000127 F0               [24]  986 	movx	@dptr,a
                                    987 ;	main.c:32: EP1INBUF[5] = 0;
      000128 90 E7 C5         [24]  988 	mov	dptr,#(_EP1INBUF + 0x0005)
      00012B F0               [24]  989 	movx	@dptr,a
                                    990 ;	main.c:33: EP1INBUF[6] = 0;
      00012C 90 E7 C6         [24]  991 	mov	dptr,#(_EP1INBUF + 0x0006)
      00012F F0               [24]  992 	movx	@dptr,a
                                    993 ;	main.c:34: EP1INBUF[7] = 0;
      000130 90 E7 C7         [24]  994 	mov	dptr,#(_EP1INBUF + 0x0007)
      000133 F0               [24]  995 	movx	@dptr,a
                                    996 ;	main.c:35: EP1INBC = 8;
      000134 90 E6 8F         [24]  997 	mov	dptr,#_EP1INBC
      000137 74 08            [12]  998 	mov	a,#0x08
      000139 F0               [24]  999 	movx	@dptr,a
                                   1000 ;	main.c:36: while (EP1INCS & b1); // BUSY
      00013A                       1001 00101$:
      00013A 90 E6 A2         [24] 1002 	mov	dptr,#_EP1INCS
      00013D E0               [24] 1003 	movx	a,@dptr
      00013E 20 E1 F9         [24] 1004 	jb	acc.1,00101$
                                   1005 ;	main.c:37: }
      000141 D0 1A            [24] 1006 	pop	_bp
      000143 22               [24] 1007 	ret
                                   1008 ;------------------------------------------------------------
                                   1009 ;Allocation info for local variables in function 'key'
                                   1010 ;------------------------------------------------------------
                                   1011 ;k             Allocated to stack - _bp -3 +1 
                                   1012 ;m             Allocated to registers r7 
                                   1013 ;------------------------------------------------------------
                                   1014 ;	main.c:39: void key(BYTE m, BYTE k) {
                                   1015 ;	-----------------------------------------
                                   1016 ;	 function key
                                   1017 ;	-----------------------------------------
      000144                       1018 _key:
      000144 C0 1A            [24] 1019 	push	_bp
      000146 85 81 1A         [24] 1020 	mov	_bp,sp
      000149 AF 82            [24] 1021 	mov	r7, dpl
                                   1022 ;	main.c:40: key_(m, k);
      00014B E5 1A            [12] 1023 	mov	a,_bp
      00014D 24 FD            [12] 1024 	add	a,#0xfd
      00014F F8               [12] 1025 	mov	r0,a
      000150 E6               [12] 1026 	mov	a,@r0
      000151 C0 E0            [24] 1027 	push	acc
      000153 8F 82            [24] 1028 	mov	dpl, r7
      000155 12 01 04         [24] 1029 	lcall	_key_
      000158 15 81            [12] 1030 	dec	sp
                                   1031 ;	main.c:41: key_(0, 0); // release
      00015A E4               [12] 1032 	clr	a
      00015B C0 E0            [24] 1033 	push	acc
      00015D 75 82 00         [24] 1034 	mov	dpl, #0x00
      000160 12 01 04         [24] 1035 	lcall	_key_
      000163 15 81            [12] 1036 	dec	sp
                                   1037 ;	main.c:42: }
      000165 D0 1A            [24] 1038 	pop	_bp
      000167 22               [24] 1039 	ret
                                   1040 ;------------------------------------------------------------
                                   1041 ;Allocation info for local variables in function 'type_char'
                                   1042 ;------------------------------------------------------------
                                   1043 ;c             Allocated to registers r7 
                                   1044 ;------------------------------------------------------------
                                   1045 ;	main.c:44: static void type_char(char c) {
                                   1046 ;	-----------------------------------------
                                   1047 ;	 function type_char
                                   1048 ;	-----------------------------------------
      000168                       1049 _type_char:
      000168 AF 82            [24] 1050 	mov	r7, dpl
                                   1051 ;	main.c:46: if (c >= 'a' && c <= 'z') {
      00016A BF 61 00         [24] 1052 	cjne	r7,#0x61,00204$
      00016D                       1053 00204$:
      00016D 40 16            [24] 1054 	jc	00102$
      00016F EF               [12] 1055 	mov	a,r7
      000170 24 85            [12] 1056 	add	a,#0xff - 0x7a
      000172 40 11            [24] 1057 	jc	00102$
                                   1058 ;	main.c:47: key(0, (BYTE)(KEY_A + (c - 'a')));
      000174 8F 06            [24] 1059 	mov	ar6,r7
      000176 74 A3            [12] 1060 	mov	a,#0xa3
      000178 2E               [12] 1061 	add	a, r6
      000179 FE               [12] 1062 	mov	r6,a
      00017A C0 06            [24] 1063 	push	ar6
      00017C 75 82 00         [24] 1064 	mov	dpl, #0x00
      00017F 12 01 44         [24] 1065 	lcall	_key
      000182 15 81            [12] 1066 	dec	sp
                                   1067 ;	main.c:48: return;
      000184 22               [24] 1068 	ret
      000185                       1069 00102$:
                                   1070 ;	main.c:51: if (c >= 'A' && c <= 'Z') {
      000185 BF 41 00         [24] 1071 	cjne	r7,#0x41,00207$
      000188                       1072 00207$:
      000188 40 16            [24] 1073 	jc	00105$
      00018A EF               [12] 1074 	mov	a,r7
      00018B 24 A5            [12] 1075 	add	a,#0xff - 0x5a
      00018D 40 11            [24] 1076 	jc	00105$
                                   1077 ;	main.c:52: key(MOD_SHIFT_LEFT, (BYTE)(KEY_A + (c - 'A')));
      00018F 8F 06            [24] 1078 	mov	ar6,r7
      000191 74 C3            [12] 1079 	mov	a,#0xc3
      000193 2E               [12] 1080 	add	a, r6
      000194 FE               [12] 1081 	mov	r6,a
      000195 C0 06            [24] 1082 	push	ar6
      000197 75 82 02         [24] 1083 	mov	dpl, #0x02
      00019A 12 01 44         [24] 1084 	lcall	_key
      00019D 15 81            [12] 1085 	dec	sp
                                   1086 ;	main.c:53: return;
      00019F 22               [24] 1087 	ret
      0001A0                       1088 00105$:
                                   1089 ;	main.c:56: if (c >= '1' && c <= '9') {
      0001A0 BF 31 00         [24] 1090 	cjne	r7,#0x31,00210$
      0001A3                       1091 00210$:
      0001A3 40 16            [24] 1092 	jc	00108$
      0001A5 EF               [12] 1093 	mov	a,r7
      0001A6 24 C6            [12] 1094 	add	a,#0xff - 0x39
      0001A8 40 11            [24] 1095 	jc	00108$
                                   1096 ;	main.c:57: key(0, (BYTE)(KEY_1 + (c - '1')));
      0001AA 8F 06            [24] 1097 	mov	ar6,r7
      0001AC 74 ED            [12] 1098 	mov	a,#0xed
      0001AE 2E               [12] 1099 	add	a, r6
      0001AF FE               [12] 1100 	mov	r6,a
      0001B0 C0 06            [24] 1101 	push	ar6
      0001B2 75 82 00         [24] 1102 	mov	dpl, #0x00
      0001B5 12 01 44         [24] 1103 	lcall	_key
      0001B8 15 81            [12] 1104 	dec	sp
                                   1105 ;	main.c:58: return;
      0001BA 22               [24] 1106 	ret
      0001BB                       1107 00108$:
                                   1108 ;	main.c:60: if (c == '0') { key(0, KEY_0); return; }
      0001BB BF 30 0D         [24] 1109 	cjne	r7,#0x30,00111$
      0001BE 74 27            [12] 1110 	mov	a,#0x27
      0001C0 C0 E0            [24] 1111 	push	acc
      0001C2 75 82 00         [24] 1112 	mov	dpl, #0x00
      0001C5 12 01 44         [24] 1113 	lcall	_key
      0001C8 15 81            [12] 1114 	dec	sp
      0001CA 22               [24] 1115 	ret
      0001CB                       1116 00111$:
                                   1117 ;	main.c:63: if (c == ' ') { key(0, KEY_SPACE); return; }
      0001CB BF 20 0D         [24] 1118 	cjne	r7,#0x20,00113$
      0001CE 74 2C            [12] 1119 	mov	a,#0x2c
      0001D0 C0 E0            [24] 1120 	push	acc
      0001D2 75 82 00         [24] 1121 	mov	dpl, #0x00
      0001D5 12 01 44         [24] 1122 	lcall	_key
      0001D8 15 81            [12] 1123 	dec	sp
      0001DA 22               [24] 1124 	ret
      0001DB                       1125 00113$:
                                   1126 ;	main.c:66: if (c == '-') { key(0, KEY_MINUS); return; }
      0001DB BF 2D 0D         [24] 1127 	cjne	r7,#0x2d,00115$
      0001DE 74 2D            [12] 1128 	mov	a,#0x2d
      0001E0 C0 E0            [24] 1129 	push	acc
      0001E2 75 82 00         [24] 1130 	mov	dpl, #0x00
      0001E5 12 01 44         [24] 1131 	lcall	_key
      0001E8 15 81            [12] 1132 	dec	sp
      0001EA 22               [24] 1133 	ret
      0001EB                       1134 00115$:
                                   1135 ;	main.c:67: if (c == '_') { key(MOD_SHIFT_LEFT, KEY_MINUS); return; }
      0001EB BF 5F 0D         [24] 1136 	cjne	r7,#0x5f,00117$
      0001EE 74 2D            [12] 1137 	mov	a,#0x2d
      0001F0 C0 E0            [24] 1138 	push	acc
      0001F2 75 82 02         [24] 1139 	mov	dpl, #0x02
      0001F5 12 01 44         [24] 1140 	lcall	_key
      0001F8 15 81            [12] 1141 	dec	sp
      0001FA 22               [24] 1142 	ret
      0001FB                       1143 00117$:
                                   1144 ;	main.c:68: if (c == '.') { key(0, KEY_DOT); return; }
      0001FB BF 2E 0D         [24] 1145 	cjne	r7,#0x2e,00119$
      0001FE 74 37            [12] 1146 	mov	a,#0x37
      000200 C0 E0            [24] 1147 	push	acc
      000202 75 82 00         [24] 1148 	mov	dpl, #0x00
      000205 12 01 44         [24] 1149 	lcall	_key
      000208 15 81            [12] 1150 	dec	sp
      00020A 22               [24] 1151 	ret
      00020B                       1152 00119$:
                                   1153 ;	main.c:69: if (c == ',') { key(0, KEY_COMMA); return; }
      00020B BF 2C 0D         [24] 1154 	cjne	r7,#0x2c,00121$
      00020E 74 36            [12] 1155 	mov	a,#0x36
      000210 C0 E0            [24] 1156 	push	acc
      000212 75 82 00         [24] 1157 	mov	dpl, #0x00
      000215 12 01 44         [24] 1158 	lcall	_key
      000218 15 81            [12] 1159 	dec	sp
      00021A 22               [24] 1160 	ret
      00021B                       1161 00121$:
                                   1162 ;	main.c:70: if (c == '/') { key(0, KEY_SLASH); return; }
      00021B BF 2F 0C         [24] 1163 	cjne	r7,#0x2f,00124$
      00021E 74 38            [12] 1164 	mov	a,#0x38
      000220 C0 E0            [24] 1165 	push	acc
      000222 75 82 00         [24] 1166 	mov	dpl, #0x00
      000225 12 01 44         [24] 1167 	lcall	_key
      000228 15 81            [12] 1168 	dec	sp
      00022A                       1169 00124$:
                                   1170 ;	main.c:73: }
      00022A 22               [24] 1171 	ret
                                   1172 ;------------------------------------------------------------
                                   1173 ;Allocation info for local variables in function 'type_str'
                                   1174 ;------------------------------------------------------------
                                   1175 ;s             Allocated to registers 
                                   1176 ;------------------------------------------------------------
                                   1177 ;	main.c:75: static void type_str(const char *s) {
                                   1178 ;	-----------------------------------------
                                   1179 ;	 function type_str
                                   1180 ;	-----------------------------------------
      00022B                       1181 _type_str:
      00022B AD 82            [24] 1182 	mov	r5, dpl
      00022D AE 83            [24] 1183 	mov	r6, dph
      00022F AF F0            [24] 1184 	mov	r7, b
                                   1185 ;	main.c:76: while (*s) {
      000231                       1186 00101$:
      000231 8D 82            [24] 1187 	mov	dpl,r5
      000233 8E 83            [24] 1188 	mov	dph,r6
      000235 8F F0            [24] 1189 	mov	b,r7
      000237 12 06 40         [24] 1190 	lcall	__gptrget
      00023A FC               [12] 1191 	mov	r4,a
      00023B 60 1E            [24] 1192 	jz	00104$
                                   1193 ;	main.c:77: type_char(*s++);
      00023D 0D               [12] 1194 	inc	r5
      00023E BD 00 01         [24] 1195 	cjne	r5,#0x00,00120$
      000241 0E               [12] 1196 	inc	r6
      000242                       1197 00120$:
      000242 8C 82            [24] 1198 	mov	dpl, r4
      000244 C0 07            [24] 1199 	push	ar7
      000246 C0 06            [24] 1200 	push	ar6
      000248 C0 05            [24] 1201 	push	ar5
      00024A 12 01 68         [24] 1202 	lcall	_type_char
                                   1203 ;	main.c:78: msleep(10);
      00024D 90 00 0A         [24] 1204 	mov	dptr,#0x000a
      000250 12 00 E8         [24] 1205 	lcall	_msleep
      000253 D0 05            [24] 1206 	pop	ar5
      000255 D0 06            [24] 1207 	pop	ar6
      000257 D0 07            [24] 1208 	pop	ar7
      000259 80 D6            [24] 1209 	sjmp	00101$
      00025B                       1210 00104$:
                                   1211 ;	main.c:80: }
      00025B 22               [24] 1212 	ret
                                   1213 ;------------------------------------------------------------
                                   1214 ;Allocation info for local variables in function 'open_spotlight'
                                   1215 ;------------------------------------------------------------
                                   1216 ;	main.c:82: static void open_spotlight(void) {
                                   1217 ;	-----------------------------------------
                                   1218 ;	 function open_spotlight
                                   1219 ;	-----------------------------------------
      00025C                       1220 _open_spotlight:
                                   1221 ;	main.c:84: key(MOD_GUI_LEFT, KEY_SPACE);
      00025C 74 2C            [12] 1222 	mov	a,#0x2c
      00025E C0 E0            [24] 1223 	push	acc
      000260 75 82 08         [24] 1224 	mov	dpl, #0x08
      000263 12 01 44         [24] 1225 	lcall	_key
      000266 15 81            [12] 1226 	dec	sp
                                   1227 ;	main.c:85: msleep(150);
      000268 90 00 96         [24] 1228 	mov	dptr,#0x0096
                                   1229 ;	main.c:86: }
      00026B 02 00 E8         [24] 1230 	ljmp	_msleep
                                   1231 ;------------------------------------------------------------
                                   1232 ;Allocation info for local variables in function 'launch_app'
                                   1233 ;------------------------------------------------------------
                                   1234 ;name          Allocated to registers r5 r6 r7 
                                   1235 ;------------------------------------------------------------
                                   1236 ;	main.c:88: static void launch_app(const char *name) {
                                   1237 ;	-----------------------------------------
                                   1238 ;	 function launch_app
                                   1239 ;	-----------------------------------------
      00026E                       1240 _launch_app:
      00026E AD 82            [24] 1241 	mov	r5, dpl
      000270 AE 83            [24] 1242 	mov	r6, dph
      000272 AF F0            [24] 1243 	mov	r7, b
                                   1244 ;	main.c:89: open_spotlight();
      000274 C0 07            [24] 1245 	push	ar7
      000276 C0 06            [24] 1246 	push	ar6
      000278 C0 05            [24] 1247 	push	ar5
      00027A 12 02 5C         [24] 1248 	lcall	_open_spotlight
      00027D D0 05            [24] 1249 	pop	ar5
      00027F D0 06            [24] 1250 	pop	ar6
      000281 D0 07            [24] 1251 	pop	ar7
                                   1252 ;	main.c:90: type_str(name);
      000283 8D 82            [24] 1253 	mov	dpl, r5
      000285 8E 83            [24] 1254 	mov	dph, r6
      000287 8F F0            [24] 1255 	mov	b, r7
      000289 12 02 2B         [24] 1256 	lcall	_type_str
                                   1257 ;	main.c:91: msleep(80);
      00028C 90 00 50         [24] 1258 	mov	dptr,#0x0050
      00028F 12 00 E8         [24] 1259 	lcall	_msleep
                                   1260 ;	main.c:92: key(0, KEY_ENTER);
      000292 74 28            [12] 1261 	mov	a,#0x28
      000294 C0 E0            [24] 1262 	push	acc
      000296 75 82 00         [24] 1263 	mov	dpl, #0x00
      000299 12 01 44         [24] 1264 	lcall	_key
      00029C 15 81            [12] 1265 	dec	sp
                                   1266 ;	main.c:93: }
      00029E 22               [24] 1267 	ret
                                   1268 ;------------------------------------------------------------
                                   1269 ;Allocation info for local variables in function 'scan4x4'
                                   1270 ;------------------------------------------------------------
                                   1271 ;	main.c:105: static void scan4x4(void) {
                                   1272 ;	-----------------------------------------
                                   1273 ;	 function scan4x4
                                   1274 ;	-----------------------------------------
      00029F                       1275 _scan4x4:
                                   1276 ;	main.c:107: PD4 = 0; PD2 = 1; PD0 = 1; PA6 = 1;
                                   1277 ;	assignBit
      00029F C2 B4            [12] 1278 	clr	_PD4
                                   1279 ;	assignBit
      0002A1 D2 B2            [12] 1280 	setb	_PD2
                                   1281 ;	assignBit
      0002A3 D2 B0            [12] 1282 	setb	_PD0
                                   1283 ;	assignBit
      0002A5 D2 86            [12] 1284 	setb	_PA6
                                   1285 ;	main.c:108: x1 = !PA4; x2 = !PA2; x3 = !PA0; xA = !PB7;
      0002A7 A2 84            [12] 1286 	mov	c,_PA4
      0002A9 B3               [12] 1287 	cpl	c
      0002AA 92 00            [24] 1288 	mov  b0,c
      0002AC E4               [12] 1289 	clr	a
      0002AD 33               [12] 1290 	rlc	a
      0002AE F5 08            [12] 1291 	mov	_x1,a
      0002B0 A2 82            [12] 1292 	mov	c,_PA2
      0002B2 B3               [12] 1293 	cpl	c
      0002B3 92 00            [24] 1294 	mov  b0,c
      0002B5 E4               [12] 1295 	clr	a
      0002B6 33               [12] 1296 	rlc	a
      0002B7 F5 09            [12] 1297 	mov	_x2,a
      0002B9 A2 80            [12] 1298 	mov	c,_PA0
      0002BB B3               [12] 1299 	cpl	c
      0002BC 92 00            [24] 1300 	mov  b0,c
      0002BE E4               [12] 1301 	clr	a
      0002BF 33               [12] 1302 	rlc	a
      0002C0 F5 0A            [12] 1303 	mov	_x3,a
      0002C2 A2 97            [12] 1304 	mov	c,_PB7
      0002C4 B3               [12] 1305 	cpl	c
      0002C5 92 00            [24] 1306 	mov  b0,c
      0002C7 E4               [12] 1307 	clr	a
      0002C8 33               [12] 1308 	rlc	a
      0002C9 F5 0B            [12] 1309 	mov	_xA,a
                                   1310 ;	main.c:111: PD4 = 1; PD2 = 0; PD0 = 1; PA6 = 1;
                                   1311 ;	assignBit
      0002CB D2 B4            [12] 1312 	setb	_PD4
                                   1313 ;	assignBit
      0002CD C2 B2            [12] 1314 	clr	_PD2
                                   1315 ;	assignBit
      0002CF D2 B0            [12] 1316 	setb	_PD0
                                   1317 ;	assignBit
      0002D1 D2 86            [12] 1318 	setb	_PA6
                                   1319 ;	main.c:112: x4 = !PA4; x5 = !PA2; x6 = !PA0; xB = !PB7;
      0002D3 A2 84            [12] 1320 	mov	c,_PA4
      0002D5 B3               [12] 1321 	cpl	c
      0002D6 92 00            [24] 1322 	mov  b0,c
      0002D8 E4               [12] 1323 	clr	a
      0002D9 33               [12] 1324 	rlc	a
      0002DA F5 0C            [12] 1325 	mov	_x4,a
      0002DC A2 82            [12] 1326 	mov	c,_PA2
      0002DE B3               [12] 1327 	cpl	c
      0002DF 92 00            [24] 1328 	mov  b0,c
      0002E1 E4               [12] 1329 	clr	a
      0002E2 33               [12] 1330 	rlc	a
      0002E3 F5 0D            [12] 1331 	mov	_x5,a
      0002E5 A2 80            [12] 1332 	mov	c,_PA0
      0002E7 B3               [12] 1333 	cpl	c
      0002E8 92 00            [24] 1334 	mov  b0,c
      0002EA E4               [12] 1335 	clr	a
      0002EB 33               [12] 1336 	rlc	a
      0002EC F5 0E            [12] 1337 	mov	_x6,a
      0002EE A2 97            [12] 1338 	mov	c,_PB7
      0002F0 B3               [12] 1339 	cpl	c
      0002F1 92 00            [24] 1340 	mov  b0,c
      0002F3 E4               [12] 1341 	clr	a
      0002F4 33               [12] 1342 	rlc	a
      0002F5 F5 0F            [12] 1343 	mov	_xB,a
                                   1344 ;	main.c:115: PD4 = 1; PD2 = 1; PD0 = 0; PA6 = 1;
                                   1345 ;	assignBit
      0002F7 D2 B4            [12] 1346 	setb	_PD4
                                   1347 ;	assignBit
      0002F9 D2 B2            [12] 1348 	setb	_PD2
                                   1349 ;	assignBit
      0002FB C2 B0            [12] 1350 	clr	_PD0
                                   1351 ;	assignBit
      0002FD D2 86            [12] 1352 	setb	_PA6
                                   1353 ;	main.c:116: x7 = !PA4; x8 = !PA2; x9 = !PA0; xC = !PB7;
      0002FF A2 84            [12] 1354 	mov	c,_PA4
      000301 B3               [12] 1355 	cpl	c
      000302 92 00            [24] 1356 	mov  b0,c
      000304 E4               [12] 1357 	clr	a
      000305 33               [12] 1358 	rlc	a
      000306 F5 10            [12] 1359 	mov	_x7,a
      000308 A2 82            [12] 1360 	mov	c,_PA2
      00030A B3               [12] 1361 	cpl	c
      00030B 92 00            [24] 1362 	mov  b0,c
      00030D E4               [12] 1363 	clr	a
      00030E 33               [12] 1364 	rlc	a
      00030F F5 11            [12] 1365 	mov	_x8,a
      000311 A2 80            [12] 1366 	mov	c,_PA0
      000313 B3               [12] 1367 	cpl	c
      000314 92 00            [24] 1368 	mov  b0,c
      000316 E4               [12] 1369 	clr	a
      000317 33               [12] 1370 	rlc	a
      000318 F5 12            [12] 1371 	mov	_x9,a
      00031A A2 97            [12] 1372 	mov	c,_PB7
      00031C B3               [12] 1373 	cpl	c
      00031D 92 00            [24] 1374 	mov  b0,c
      00031F E4               [12] 1375 	clr	a
      000320 33               [12] 1376 	rlc	a
      000321 F5 13            [12] 1377 	mov	_xC,a
                                   1378 ;	main.c:119: PD4 = 1; PD2 = 1; PD0 = 1; PA6 = 0;
                                   1379 ;	assignBit
      000323 D2 B4            [12] 1380 	setb	_PD4
                                   1381 ;	assignBit
      000325 D2 B2            [12] 1382 	setb	_PD2
                                   1383 ;	assignBit
      000327 D2 B0            [12] 1384 	setb	_PD0
                                   1385 ;	assignBit
      000329 C2 86            [12] 1386 	clr	_PA6
                                   1387 ;	main.c:120: xK = !PA4; x0 = !PA2; xS = !PA0; xD = !PB7;
      00032B A2 84            [12] 1388 	mov	c,_PA4
      00032D B3               [12] 1389 	cpl	c
      00032E 92 00            [24] 1390 	mov  b0,c
      000330 E4               [12] 1391 	clr	a
      000331 33               [12] 1392 	rlc	a
      000332 F5 14            [12] 1393 	mov	_xK,a
      000334 A2 82            [12] 1394 	mov	c,_PA2
      000336 B3               [12] 1395 	cpl	c
      000337 92 00            [24] 1396 	mov  b0,c
      000339 E4               [12] 1397 	clr	a
      00033A 33               [12] 1398 	rlc	a
      00033B F5 15            [12] 1399 	mov	_x0,a
      00033D A2 80            [12] 1400 	mov	c,_PA0
      00033F B3               [12] 1401 	cpl	c
      000340 92 00            [24] 1402 	mov  b0,c
      000342 E4               [12] 1403 	clr	a
      000343 33               [12] 1404 	rlc	a
      000344 F5 16            [12] 1405 	mov	_xS,a
      000346 A2 97            [12] 1406 	mov	c,_PB7
      000348 B3               [12] 1407 	cpl	c
      000349 92 00            [24] 1408 	mov  b0,c
      00034B E4               [12] 1409 	clr	a
      00034C 33               [12] 1410 	rlc	a
      00034D F5 17            [12] 1411 	mov	_xD,a
                                   1412 ;	main.c:121: }
      00034F 22               [24] 1413 	ret
                                   1414 ;------------------------------------------------------------
                                   1415 ;Allocation info for local variables in function 'goodusb_loop'
                                   1416 ;------------------------------------------------------------
                                   1417 ;any           Allocated to registers r6 
                                   1418 ;------------------------------------------------------------
                                   1419 ;	main.c:126: static void goodusb_loop(void) {
                                   1420 ;	-----------------------------------------
                                   1421 ;	 function goodusb_loop
                                   1422 ;	-----------------------------------------
      000350                       1423 _goodusb_loop:
                                   1424 ;	main.c:127: scan4x4();
      000350 12 02 9F         [24] 1425 	lcall	_scan4x4
                                   1426 ;	main.c:129: BYTE any = x1||x2||x3||xA||x4||x5||x6||xB||x7||x8||x9||xC||xK||x0||xS||xD;
      000353 E5 08            [12] 1427 	mov	a,_x1
      000355 70 40            [24] 1428 	jnz	00107$
      000357 E5 09            [12] 1429 	mov	a,_x2
      000359 70 3C            [24] 1430 	jnz	00107$
      00035B E5 0A            [12] 1431 	mov	a,_x3
      00035D 70 38            [24] 1432 	jnz	00107$
      00035F E5 0B            [12] 1433 	mov	a,_xA
      000361 70 34            [24] 1434 	jnz	00107$
      000363 E5 0C            [12] 1435 	mov	a,_x4
      000365 70 30            [24] 1436 	jnz	00107$
      000367 E5 0D            [12] 1437 	mov	a,_x5
      000369 70 2C            [24] 1438 	jnz	00107$
      00036B E5 0E            [12] 1439 	mov	a,_x6
      00036D 70 28            [24] 1440 	jnz	00107$
      00036F E5 0F            [12] 1441 	mov	a,_xB
      000371 70 24            [24] 1442 	jnz	00107$
      000373 E5 10            [12] 1443 	mov	a,_x7
      000375 70 20            [24] 1444 	jnz	00107$
      000377 E5 11            [12] 1445 	mov	a,_x8
      000379 70 1C            [24] 1446 	jnz	00107$
      00037B E5 12            [12] 1447 	mov	a,_x9
      00037D 70 18            [24] 1448 	jnz	00107$
      00037F E5 13            [12] 1449 	mov	a,_xC
      000381 70 14            [24] 1450 	jnz	00107$
      000383 E5 14            [12] 1451 	mov	a,_xK
      000385 70 10            [24] 1452 	jnz	00107$
      000387 E5 15            [12] 1453 	mov	a,_x0
      000389 70 0C            [24] 1454 	jnz	00107$
      00038B E5 16            [12] 1455 	mov	a,_xS
      00038D 70 08            [24] 1456 	jnz	00107$
      00038F E5 17            [12] 1457 	mov	a,_xD
      000391 70 04            [24] 1458 	jnz	00107$
                                   1459 ;	assignBit
      000393 C2 00            [12] 1460 	clr	b0
      000395 80 02            [24] 1461 	sjmp	00108$
      000397                       1462 00107$:
                                   1463 ;	assignBit
      000397 D2 00            [12] 1464 	setb	b0
      000399                       1465 00108$:
      000399 A2 00            [12] 1466 	mov	c,b0
      00039B E4               [12] 1467 	clr	a
      00039C 33               [12] 1468 	rlc	a
                                   1469 ;	main.c:131: if (any && !p_any) {
      00039D FE               [12] 1470 	mov	r6,a
      00039E 60 14            [24] 1471 	jz	00102$
      0003A0 E5 18            [12] 1472 	mov	a,_p_any
      0003A2 70 10            [24] 1473 	jnz	00102$
                                   1474 ;	main.c:133: key(0, KEY_A);
      0003A4 C0 06            [24] 1475 	push	ar6
      0003A6 74 04            [12] 1476 	mov	a,#0x04
      0003A8 C0 E0            [24] 1477 	push	acc
      0003AA 75 82 00         [24] 1478 	mov	dpl, #0x00
      0003AD 12 01 44         [24] 1479 	lcall	_key
      0003B0 15 81            [12] 1480 	dec	sp
      0003B2 D0 06            [24] 1481 	pop	ar6
      0003B4                       1482 00102$:
                                   1483 ;	main.c:136: p_any = any;
      0003B4 8E 18            [24] 1484 	mov	_p_any,r6
                                   1485 ;	main.c:137: msleep(10);
      0003B6 90 00 0A         [24] 1486 	mov	dptr,#0x000a
                                   1487 ;	main.c:138: }
      0003B9 02 00 E8         [24] 1488 	ljmp	_msleep
                                   1489 ;------------------------------------------------------------
                                   1490 ;Allocation info for local variables in function 'main'
                                   1491 ;------------------------------------------------------------
                                   1492 ;	main.c:144: void main(void) {
                                   1493 ;	-----------------------------------------
                                   1494 ;	 function main
                                   1495 ;	-----------------------------------------
      0003BC                       1496 _main:
                                   1497 ;	main.c:145: CPUCS = b4;        // set CPU clock (b4=1,b3=0:48MHz)
      0003BC 90 E6 00         [24] 1498 	mov	dptr,#_CPUCS
      0003BF 74 10            [12] 1499 	mov	a,#0x10
      0003C1 F0               [24] 1500 	movx	@dptr,a
                                   1501 ;	main.c:146: IFCONFIG |= b6;    // set FIFO clock (b6=1:48MHz)
      0003C2 90 E6 01         [24] 1502 	mov	dptr,#_IFCONFIG
      0003C5 E0               [24] 1503 	movx	a,@dptr
      0003C6 43 E0 40         [24] 1504 	orl	acc,#0x40
      0003C9 F0               [24] 1505 	movx	@dptr,a
                                   1506 ;	main.c:149: EP1INCFG  = b7|b5|b4; // VALID | IN | INT
      0003CA 90 E6 11         [24] 1507 	mov	dptr,#_EP1INCFG
      0003CD 74 B0            [12] 1508 	mov	a,#0xb0
      0003CF F0               [24] 1509 	movx	@dptr,a
                                   1510 ;	main.c:150: EP1OUTCFG = b7|b5;    // (default: bulk) VALID | OUT
      0003D0 90 E6 10         [24] 1511 	mov	dptr,#_EP1OUTCFG
      0003D3 74 A0            [12] 1512 	mov	a,#0xa0
      0003D5 F0               [24] 1513 	movx	@dptr,a
                                   1514 ;	main.c:153: EP2CFG = 0xF2;     // setup EP2
      0003D6 90 E6 12         [24] 1515 	mov	dptr,#_EP2CFG
      0003D9 74 F2            [12] 1516 	mov	a,#0xf2
      0003DB F0               [24] 1517 	movx	@dptr,a
                                   1518 ;	main.c:154: EP4CFG = 0;        // disable EP4
      0003DC 90 E6 13         [24] 1519 	mov	dptr,#_EP4CFG
      0003DF E4               [12] 1520 	clr	a
      0003E0 F0               [24] 1521 	movx	@dptr,a
                                   1522 ;	main.c:155: EP6CFG = 0;        // disable EP6
      0003E1 90 E6 14         [24] 1523 	mov	dptr,#_EP6CFG
      0003E4 F0               [24] 1524 	movx	@dptr,a
                                   1525 ;	main.c:156: EP8CFG = 0;        // disable EP8
      0003E5 90 E6 15         [24] 1526 	mov	dptr,#_EP8CFG
      0003E8 F0               [24] 1527 	movx	@dptr,a
                                   1528 ;	main.c:158: USBIE = b4|b0;     // reset IRQ, setup available IRQ
      0003E9 90 E6 5C         [24] 1529 	mov	dptr,#_USBIE
      0003EC 74 11            [12] 1530 	mov	a,#0x11
      0003EE F0               [24] 1531 	movx	@dptr,a
                                   1532 ;	main.c:159: EIE  |= b0;        // enable USB interrupt
      0003EF 43 E8 01         [24] 1533 	orl	_EIE,#0x01
                                   1534 ;	main.c:160: IE   |= b7;        // global interrupt enable
      0003F2 43 A8 80         [24] 1535 	orl	_IE,#0x80
                                   1536 ;	main.c:163: USBCS = b3|b1;     // DISCON | RENUM
      0003F5 90 E6 80         [24] 1537 	mov	dptr,#_USBCS
      0003F8 74 0A            [12] 1538 	mov	a,#0x0a
      0003FA F0               [24] 1539 	movx	@dptr,a
                                   1540 ;	main.c:164: SYNCDELAY;
      0003FB 00               [12] 1541 	nop 
      0003FC 00               [12] 1542 	nop 
      0003FD 00               [12] 1543 	nop 
      0003FE 00               [12] 1544 	nop 
                                   1545 ;	main.c:165: USBCS &= ~b3;      // ~DISCON
      0003FF 90 E6 80         [24] 1546 	mov	dptr,#_USBCS
      000402 E0               [24] 1547 	movx	a,@dptr
      000403 53 E0 F7         [24] 1548 	anl	acc,#0xf7
      000406 F0               [24] 1549 	movx	@dptr,a
                                   1550 ;	main.c:169: OED = b4|b2|b0;         // out: PD4,PD2,PD0
      000407 75 B5 15         [24] 1551 	mov	_OED,#0x15
                                   1552 ;	main.c:170: OEA = b6|b1;            // out: PA6,PA1 (in: PA0,PA2,PA4)
      00040A 75 B2 42         [24] 1553 	mov	_OEA,#0x42
                                   1554 ;	main.c:171: OEB = 0;                // in: PB0-PB7
      00040D 75 B3 00         [24] 1555 	mov	_OEB,#0x00
                                   1556 ;	main.c:173: PA1 = 1;                // D2:LED off
                                   1557 ;	assignBit
      000410 D2 81            [12] 1558 	setb	_PA1
                                   1559 ;	main.c:176: msleep(1500);
      000412 90 05 DC         [24] 1560 	mov	dptr,#0x05dc
      000415 12 00 E8         [24] 1561 	lcall	_msleep
      000418                       1562 00117$:
                                   1563 ;	main.c:179: goodusb_loop();
      000418 12 03 50         [24] 1564 	lcall	_goodusb_loop
                                   1565 ;	main.c:181: }
      00041B 80 FB            [24] 1566 	sjmp	00117$
                                   1567 	.area CSEG    (CODE)
                                   1568 	.area CONST   (CODE)
                                   1569 	.area XINIT   (CODE)
                                   1570 	.area CABS    (ABS,CODE)
