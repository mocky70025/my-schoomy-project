                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.0 #15242 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module isr
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _StringDscr
                                     12 	.globl _isr
                                     13 	.globl _hid_report
                                     14 	.globl _EIPX6
                                     15 	.globl _EIPX5
                                     16 	.globl _EIPX4
                                     17 	.globl _PI2C
                                     18 	.globl _PUSB
                                     19 	.globl _EIEX6
                                     20 	.globl _EIEX5
                                     21 	.globl _EIEX4
                                     22 	.globl _EI2C
                                     23 	.globl _EUSB
                                     24 	.globl _SMOD1
                                     25 	.globl _ERESI
                                     26 	.globl _RESI
                                     27 	.globl _INT6
                                     28 	.globl _CY
                                     29 	.globl _AC
                                     30 	.globl _F0
                                     31 	.globl _RS1
                                     32 	.globl _RS0
                                     33 	.globl _OV
                                     34 	.globl _FL
                                     35 	.globl _P
                                     36 	.globl _TF2
                                     37 	.globl _EXF2
                                     38 	.globl _RCLK
                                     39 	.globl _TCLK
                                     40 	.globl _EXEN2
                                     41 	.globl _TR2
                                     42 	.globl _C_T2
                                     43 	.globl _CP_RL2
                                     44 	.globl _SM01
                                     45 	.globl _SM11
                                     46 	.globl _SM21
                                     47 	.globl _REN1
                                     48 	.globl _TB81
                                     49 	.globl _RB81
                                     50 	.globl _TI1
                                     51 	.globl _RI1
                                     52 	.globl _PS1
                                     53 	.globl _PT2
                                     54 	.globl _PS0
                                     55 	.globl _PT1
                                     56 	.globl _PX1
                                     57 	.globl _PT0
                                     58 	.globl _PX0
                                     59 	.globl _PD7
                                     60 	.globl _PD6
                                     61 	.globl _PD5
                                     62 	.globl _PD4
                                     63 	.globl _PD3
                                     64 	.globl _PD2
                                     65 	.globl _PD1
                                     66 	.globl _PD0
                                     67 	.globl _EA
                                     68 	.globl _ES1
                                     69 	.globl _ET2
                                     70 	.globl _ES0
                                     71 	.globl _ET1
                                     72 	.globl _EX1
                                     73 	.globl _ET0
                                     74 	.globl _EX0
                                     75 	.globl _PC7
                                     76 	.globl _PC6
                                     77 	.globl _PC5
                                     78 	.globl _PC4
                                     79 	.globl _PC3
                                     80 	.globl _PC2
                                     81 	.globl _PC1
                                     82 	.globl _PC0
                                     83 	.globl _SM0
                                     84 	.globl _SM1
                                     85 	.globl _SM2
                                     86 	.globl _REN
                                     87 	.globl _TB8
                                     88 	.globl _RB8
                                     89 	.globl _TI
                                     90 	.globl _RI
                                     91 	.globl _PB7
                                     92 	.globl _PB6
                                     93 	.globl _PB5
                                     94 	.globl _PB4
                                     95 	.globl _PB3
                                     96 	.globl _PB2
                                     97 	.globl _PB1
                                     98 	.globl _PB0
                                     99 	.globl _TF1
                                    100 	.globl _TR1
                                    101 	.globl _TF0
                                    102 	.globl _TR0
                                    103 	.globl _IE1
                                    104 	.globl _IT1
                                    105 	.globl _IE0
                                    106 	.globl _IT0
                                    107 	.globl _PA7
                                    108 	.globl _PA6
                                    109 	.globl _PA5
                                    110 	.globl _PA4
                                    111 	.globl _PA3
                                    112 	.globl _PA2
                                    113 	.globl _PA1
                                    114 	.globl _PA0
                                    115 	.globl _EIP
                                    116 	.globl _B
                                    117 	.globl _EIE
                                    118 	.globl _ACC
                                    119 	.globl _EICON
                                    120 	.globl _PSW
                                    121 	.globl _TH2
                                    122 	.globl _TL2
                                    123 	.globl _RCAP2H
                                    124 	.globl _RCAP2L
                                    125 	.globl _T2CON
                                    126 	.globl _SBUF1
                                    127 	.globl _SCON1
                                    128 	.globl _GPIFSGLDATLNOX
                                    129 	.globl _GPIFSGLDATLX
                                    130 	.globl _GPIFSGLDATH
                                    131 	.globl _GPIFTRIG
                                    132 	.globl _EP01STAT
                                    133 	.globl _IP
                                    134 	.globl _OEE
                                    135 	.globl _OED
                                    136 	.globl _OEC
                                    137 	.globl _OEB
                                    138 	.globl _OEA
                                    139 	.globl _IOE
                                    140 	.globl _IOD
                                    141 	.globl _AUTOPTRSETUP
                                    142 	.globl _EP68FIFOFLGS
                                    143 	.globl _EP24FIFOFLGS
                                    144 	.globl _EP2468STAT
                                    145 	.globl _IE
                                    146 	.globl _INT4CLR
                                    147 	.globl _INT2CLR
                                    148 	.globl _IOC
                                    149 	.globl _AUTOPTRL2
                                    150 	.globl _AUTOPTRH2
                                    151 	.globl _AUTOPTRL1
                                    152 	.globl _AUTOPTRH1
                                    153 	.globl _SBUF0
                                    154 	.globl _SCON0
                                    155 	.globl _MPAGE
                                    156 	.globl _EXIF
                                    157 	.globl _IOB
                                    158 	.globl _CKCON
                                    159 	.globl _TH1
                                    160 	.globl _TH0
                                    161 	.globl _TL1
                                    162 	.globl _TL0
                                    163 	.globl _TMOD
                                    164 	.globl _TCON
                                    165 	.globl _PCON
                                    166 	.globl _DPS
                                    167 	.globl _DPH1
                                    168 	.globl _DPL1
                                    169 	.globl _DPH
                                    170 	.globl _DPL
                                    171 	.globl _SP
                                    172 	.globl _IOA
                                    173 	.globl _EP8FIFOBUF
                                    174 	.globl _EP6FIFOBUF
                                    175 	.globl _EP4FIFOBUF
                                    176 	.globl _EP2FIFOBUF
                                    177 	.globl _EP1INBUF
                                    178 	.globl _EP1OUTBUF
                                    179 	.globl _EP0BUF
                                    180 	.globl _GPIFABORT
                                    181 	.globl _GPIFREADYSTAT
                                    182 	.globl _GPIFREADYCFG
                                    183 	.globl _XGPIFSGLDATLNOX
                                    184 	.globl _XGPIFSGLDATLX
                                    185 	.globl _XGPIFSGLDATH
                                    186 	.globl _EP8GPIFTRIG
                                    187 	.globl _EP8GPIFPFSTOP
                                    188 	.globl _EP8GPIFFLGSEL
                                    189 	.globl _EP6GPIFTRIG
                                    190 	.globl _EP6GPIFPFSTOP
                                    191 	.globl _EP6GPIFFLGSEL
                                    192 	.globl _EP4GPIFTRIG
                                    193 	.globl _EP4GPIFPFSTOP
                                    194 	.globl _EP4GPIFFLGSEL
                                    195 	.globl _EP2GPIFTRIG
                                    196 	.globl _EP2GPIFPFSTOP
                                    197 	.globl _EP2GPIFFLGSEL
                                    198 	.globl _GPIFTCB0
                                    199 	.globl _GPIFTCB1
                                    200 	.globl _GPIFTCB2
                                    201 	.globl _GPIFTCB3
                                    202 	.globl _FLOWSTBHPERIOD
                                    203 	.globl _FLOWSTBEDGE
                                    204 	.globl _FLOWSTB
                                    205 	.globl _FLOWHOLDOFF
                                    206 	.globl _FLOWEQ1CTL
                                    207 	.globl _FLOWEQ0CTL
                                    208 	.globl _FLOWLOGIC
                                    209 	.globl _FLOWSTATE
                                    210 	.globl _GPIFADRL
                                    211 	.globl _GPIFADRH
                                    212 	.globl _GPIFCTLCFG
                                    213 	.globl _GPIFIDLECTL
                                    214 	.globl _GPIFIDLECS
                                    215 	.globl _GPIFWFSELECT
                                    216 	.globl _SETUPDAT
                                    217 	.globl _SUDPTRCTL
                                    218 	.globl _SUDPTRL
                                    219 	.globl _SUDPTRH
                                    220 	.globl _EP8FIFOBCL
                                    221 	.globl _EP8FIFOBCH
                                    222 	.globl _EP6FIFOBCL
                                    223 	.globl _EP6FIFOBCH
                                    224 	.globl _EP4FIFOBCL
                                    225 	.globl _EP4FIFOBCH
                                    226 	.globl _EP2FIFOBCL
                                    227 	.globl _EP2FIFOBCH
                                    228 	.globl _EP8FIFOFLGS
                                    229 	.globl _EP6FIFOFLGS
                                    230 	.globl _EP4FIFOFLGS
                                    231 	.globl _EP2FIFOFLGS
                                    232 	.globl _EP8CS
                                    233 	.globl _EP6CS
                                    234 	.globl _EP4CS
                                    235 	.globl _EP2CS
                                    236 	.globl _EP1INCS
                                    237 	.globl _EP1OUTCS
                                    238 	.globl _EP0CS
                                    239 	.globl _EP8BCL
                                    240 	.globl _EP8BCH
                                    241 	.globl _EP6BCL
                                    242 	.globl _EP6BCH
                                    243 	.globl _EP4BCL
                                    244 	.globl _EP4BCH
                                    245 	.globl _EP2BCL
                                    246 	.globl _EP2BCH
                                    247 	.globl _EP1INBC
                                    248 	.globl _EP1OUTBC
                                    249 	.globl _EP0BCL
                                    250 	.globl _EP0BCH
                                    251 	.globl _FNADDR
                                    252 	.globl _MICROFRAME
                                    253 	.globl _USBFRAMEL
                                    254 	.globl _USBFRAMEH
                                    255 	.globl _TOGCTL
                                    256 	.globl _WAKEUPCS
                                    257 	.globl _SUSPEND
                                    258 	.globl _USBCS
                                    259 	.globl _UDMACRCQUAL
                                    260 	.globl _UDMACRCL
                                    261 	.globl _UDMACRCH
                                    262 	.globl _XAUTODAT2
                                    263 	.globl _XAUTODAT1
                                    264 	.globl _I2CTL
                                    265 	.globl _I2DAT
                                    266 	.globl _I2CS
                                    267 	.globl _PORTECFG
                                    268 	.globl _PORTCCFG
                                    269 	.globl _PORTACFG
                                    270 	.globl _INTSETUP
                                    271 	.globl _INT4IVEC
                                    272 	.globl _INT2IVEC
                                    273 	.globl _CLRERRCNT
                                    274 	.globl _ERRCNTLIM
                                    275 	.globl _USBERRIRQ
                                    276 	.globl _USBERRIE
                                    277 	.globl _GPIFIRQ
                                    278 	.globl _GPIFIE
                                    279 	.globl _EPIRQ
                                    280 	.globl _EPIE
                                    281 	.globl _USBIRQ
                                    282 	.globl _USBIE
                                    283 	.globl _NAKIRQ
                                    284 	.globl _NAKIE
                                    285 	.globl _IBNIRQ
                                    286 	.globl _IBNIE
                                    287 	.globl _EP8FIFOIRQ
                                    288 	.globl _EP8FIFOIE
                                    289 	.globl _EP6FIFOIRQ
                                    290 	.globl _EP6FIFOIE
                                    291 	.globl _EP4FIFOIRQ
                                    292 	.globl _EP4FIFOIE
                                    293 	.globl _EP2FIFOIRQ
                                    294 	.globl _EP2FIFOIE
                                    295 	.globl _OUTPKTEND
                                    296 	.globl _INPKTEND
                                    297 	.globl _EP8ISOINPKTS
                                    298 	.globl _EP6ISOINPKTS
                                    299 	.globl _EP4ISOINPKTS
                                    300 	.globl _EP2ISOINPKTS
                                    301 	.globl _EP8FIFOPFL
                                    302 	.globl _EP8FIFOPFH
                                    303 	.globl _EP6FIFOPFL
                                    304 	.globl _EP6FIFOPFH
                                    305 	.globl _EP4FIFOPFL
                                    306 	.globl _EP4FIFOPFH
                                    307 	.globl _EP2FIFOPFL
                                    308 	.globl _EP2FIFOPFH
                                    309 	.globl _ECC2B2
                                    310 	.globl _ECC2B1
                                    311 	.globl _ECC2B0
                                    312 	.globl _ECC1B2
                                    313 	.globl _ECC1B1
                                    314 	.globl _ECC1B0
                                    315 	.globl _ECCRESET
                                    316 	.globl _ECCCFG
                                    317 	.globl _EP8AUTOINLENL
                                    318 	.globl _EP8AUTOINLENH
                                    319 	.globl _EP6AUTOINLENL
                                    320 	.globl _EP6AUTOINLENH
                                    321 	.globl _EP4AUTOINLENL
                                    322 	.globl _EP4AUTOINLENH
                                    323 	.globl _EP2AUTOINLENL
                                    324 	.globl _EP2AUTOINLENH
                                    325 	.globl _EP8FIFOCFG
                                    326 	.globl _EP6FIFOCFG
                                    327 	.globl _EP4FIFOCFG
                                    328 	.globl _EP2FIFOCFG
                                    329 	.globl _EP8CFG
                                    330 	.globl _EP6CFG
                                    331 	.globl _EP4CFG
                                    332 	.globl _EP2CFG
                                    333 	.globl _EP1INCFG
                                    334 	.globl _EP1OUTCFG
                                    335 	.globl _GPIFHOLDAMOUNT
                                    336 	.globl _REVCTL
                                    337 	.globl _REVID
                                    338 	.globl _FIFOPINPOLAR
                                    339 	.globl _UART230
                                    340 	.globl _BPADDRL
                                    341 	.globl _BPADDRH
                                    342 	.globl _BREAKPT
                                    343 	.globl _FIFORESET
                                    344 	.globl _PINFLAGSCD
                                    345 	.globl _PINFLAGSAB
                                    346 	.globl _IFCONFIG
                                    347 	.globl _CPUCS
                                    348 	.globl _WAVEDATA
                                    349 ;--------------------------------------------------------
                                    350 ; special function registers
                                    351 ;--------------------------------------------------------
                                    352 	.area RSEG    (ABS,DATA)
      000000                        353 	.org 0x0000
                           000080   354 _IOA	=	0x0080
                           000081   355 _SP	=	0x0081
                           000082   356 _DPL	=	0x0082
                           000083   357 _DPH	=	0x0083
                           000084   358 _DPL1	=	0x0084
                           000085   359 _DPH1	=	0x0085
                           000086   360 _DPS	=	0x0086
                           000087   361 _PCON	=	0x0087
                           000088   362 _TCON	=	0x0088
                           000089   363 _TMOD	=	0x0089
                           00008A   364 _TL0	=	0x008a
                           00008B   365 _TL1	=	0x008b
                           00008C   366 _TH0	=	0x008c
                           00008D   367 _TH1	=	0x008d
                           00008E   368 _CKCON	=	0x008e
                           000090   369 _IOB	=	0x0090
                           000091   370 _EXIF	=	0x0091
                           000092   371 _MPAGE	=	0x0092
                           000098   372 _SCON0	=	0x0098
                           000099   373 _SBUF0	=	0x0099
                           00009A   374 _AUTOPTRH1	=	0x009a
                           00009B   375 _AUTOPTRL1	=	0x009b
                           00009D   376 _AUTOPTRH2	=	0x009d
                           00009E   377 _AUTOPTRL2	=	0x009e
                           0000A0   378 _IOC	=	0x00a0
                           0000A1   379 _INT2CLR	=	0x00a1
                           0000A2   380 _INT4CLR	=	0x00a2
                           0000A8   381 _IE	=	0x00a8
                           0000AA   382 _EP2468STAT	=	0x00aa
                           0000AB   383 _EP24FIFOFLGS	=	0x00ab
                           0000AC   384 _EP68FIFOFLGS	=	0x00ac
                           0000AF   385 _AUTOPTRSETUP	=	0x00af
                           0000B0   386 _IOD	=	0x00b0
                           0000B1   387 _IOE	=	0x00b1
                           0000B2   388 _OEA	=	0x00b2
                           0000B3   389 _OEB	=	0x00b3
                           0000B4   390 _OEC	=	0x00b4
                           0000B5   391 _OED	=	0x00b5
                           0000B6   392 _OEE	=	0x00b6
                           0000B8   393 _IP	=	0x00b8
                           0000BA   394 _EP01STAT	=	0x00ba
                           0000BB   395 _GPIFTRIG	=	0x00bb
                           0000BD   396 _GPIFSGLDATH	=	0x00bd
                           0000BE   397 _GPIFSGLDATLX	=	0x00be
                           0000BF   398 _GPIFSGLDATLNOX	=	0x00bf
                           0000C0   399 _SCON1	=	0x00c0
                           0000C1   400 _SBUF1	=	0x00c1
                           0000C8   401 _T2CON	=	0x00c8
                           0000CA   402 _RCAP2L	=	0x00ca
                           0000CB   403 _RCAP2H	=	0x00cb
                           0000CC   404 _TL2	=	0x00cc
                           0000CD   405 _TH2	=	0x00cd
                           0000D0   406 _PSW	=	0x00d0
                           0000D8   407 _EICON	=	0x00d8
                           0000E0   408 _ACC	=	0x00e0
                           0000E8   409 _EIE	=	0x00e8
                           0000F0   410 _B	=	0x00f0
                           0000F8   411 _EIP	=	0x00f8
                                    412 ;--------------------------------------------------------
                                    413 ; special function bits
                                    414 ;--------------------------------------------------------
                                    415 	.area RSEG    (ABS,DATA)
      000000                        416 	.org 0x0000
                           000080   417 _PA0	=	0x0080
                           000081   418 _PA1	=	0x0081
                           000082   419 _PA2	=	0x0082
                           000083   420 _PA3	=	0x0083
                           000084   421 _PA4	=	0x0084
                           000085   422 _PA5	=	0x0085
                           000086   423 _PA6	=	0x0086
                           000087   424 _PA7	=	0x0087
                           000088   425 _IT0	=	0x0088
                           000089   426 _IE0	=	0x0089
                           00008A   427 _IT1	=	0x008a
                           00008B   428 _IE1	=	0x008b
                           00008C   429 _TR0	=	0x008c
                           00008D   430 _TF0	=	0x008d
                           00008E   431 _TR1	=	0x008e
                           00008F   432 _TF1	=	0x008f
                           000090   433 _PB0	=	0x0090
                           000091   434 _PB1	=	0x0091
                           000092   435 _PB2	=	0x0092
                           000093   436 _PB3	=	0x0093
                           000094   437 _PB4	=	0x0094
                           000095   438 _PB5	=	0x0095
                           000096   439 _PB6	=	0x0096
                           000097   440 _PB7	=	0x0097
                           000098   441 _RI	=	0x0098
                           000099   442 _TI	=	0x0099
                           00009A   443 _RB8	=	0x009a
                           00009B   444 _TB8	=	0x009b
                           00009C   445 _REN	=	0x009c
                           00009D   446 _SM2	=	0x009d
                           00009E   447 _SM1	=	0x009e
                           00009F   448 _SM0	=	0x009f
                           0000A0   449 _PC0	=	0x00a0
                           0000A1   450 _PC1	=	0x00a1
                           0000A2   451 _PC2	=	0x00a2
                           0000A3   452 _PC3	=	0x00a3
                           0000A4   453 _PC4	=	0x00a4
                           0000A5   454 _PC5	=	0x00a5
                           0000A6   455 _PC6	=	0x00a6
                           0000A7   456 _PC7	=	0x00a7
                           0000A8   457 _EX0	=	0x00a8
                           0000A9   458 _ET0	=	0x00a9
                           0000AA   459 _EX1	=	0x00aa
                           0000AB   460 _ET1	=	0x00ab
                           0000AC   461 _ES0	=	0x00ac
                           0000AD   462 _ET2	=	0x00ad
                           0000AE   463 _ES1	=	0x00ae
                           0000AF   464 _EA	=	0x00af
                           0000B0   465 _PD0	=	0x00b0
                           0000B1   466 _PD1	=	0x00b1
                           0000B2   467 _PD2	=	0x00b2
                           0000B3   468 _PD3	=	0x00b3
                           0000B4   469 _PD4	=	0x00b4
                           0000B5   470 _PD5	=	0x00b5
                           0000B6   471 _PD6	=	0x00b6
                           0000B7   472 _PD7	=	0x00b7
                           0000B8   473 _PX0	=	0x00b8
                           0000B9   474 _PT0	=	0x00b9
                           0000BA   475 _PX1	=	0x00ba
                           0000BB   476 _PT1	=	0x00bb
                           0000BC   477 _PS0	=	0x00bc
                           0000BD   478 _PT2	=	0x00bd
                           0000BE   479 _PS1	=	0x00be
                           0000C0   480 _RI1	=	0x00c0
                           0000C1   481 _TI1	=	0x00c1
                           0000C2   482 _RB81	=	0x00c2
                           0000C3   483 _TB81	=	0x00c3
                           0000C4   484 _REN1	=	0x00c4
                           0000C5   485 _SM21	=	0x00c5
                           0000C6   486 _SM11	=	0x00c6
                           0000C7   487 _SM01	=	0x00c7
                           0000C8   488 _CP_RL2	=	0x00c8
                           0000C9   489 _C_T2	=	0x00c9
                           0000CA   490 _TR2	=	0x00ca
                           0000CB   491 _EXEN2	=	0x00cb
                           0000CC   492 _TCLK	=	0x00cc
                           0000CD   493 _RCLK	=	0x00cd
                           0000CE   494 _EXF2	=	0x00ce
                           0000CF   495 _TF2	=	0x00cf
                           0000D0   496 _P	=	0x00d0
                           0000D1   497 _FL	=	0x00d1
                           0000D2   498 _OV	=	0x00d2
                           0000D3   499 _RS0	=	0x00d3
                           0000D4   500 _RS1	=	0x00d4
                           0000D5   501 _F0	=	0x00d5
                           0000D6   502 _AC	=	0x00d6
                           0000D7   503 _CY	=	0x00d7
                           0000DB   504 _INT6	=	0x00db
                           0000DC   505 _RESI	=	0x00dc
                           0000DD   506 _ERESI	=	0x00dd
                           0000DF   507 _SMOD1	=	0x00df
                           0000E8   508 _EUSB	=	0x00e8
                           0000E9   509 _EI2C	=	0x00e9
                           0000EA   510 _EIEX4	=	0x00ea
                           0000EB   511 _EIEX5	=	0x00eb
                           0000EC   512 _EIEX6	=	0x00ec
                           0000F8   513 _PUSB	=	0x00f8
                           0000F9   514 _PI2C	=	0x00f9
                           0000FA   515 _EIPX4	=	0x00fa
                           0000FB   516 _EIPX5	=	0x00fb
                           0000FC   517 _EIPX6	=	0x00fc
                                    518 ;--------------------------------------------------------
                                    519 ; overlayable register banks
                                    520 ;--------------------------------------------------------
                                    521 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        522 	.ds 8
                                    523 ;--------------------------------------------------------
                                    524 ; overlayable bit register bank
                                    525 ;--------------------------------------------------------
                                    526 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        527 bits:
      000020                        528 	.ds 1
                           008000   529 	b0 = bits[0]
                           008100   530 	b1 = bits[1]
                           008200   531 	b2 = bits[2]
                           008300   532 	b3 = bits[3]
                           008400   533 	b4 = bits[4]
                           008500   534 	b5 = bits[5]
                           008600   535 	b6 = bits[6]
                           008700   536 	b7 = bits[7]
                                    537 ;--------------------------------------------------------
                                    538 ; internal ram data
                                    539 ;--------------------------------------------------------
                                    540 	.area DSEG    (DATA)
      000019                        541 _isr_config_30000_18:
      000019                        542 	.ds 1
                                    543 ;--------------------------------------------------------
                                    544 ; overlayable items in internal ram
                                    545 ;--------------------------------------------------------
                                    546 ;--------------------------------------------------------
                                    547 ; indirectly addressable internal ram data
                                    548 ;--------------------------------------------------------
                                    549 	.area ISEG    (DATA)
                                    550 ;--------------------------------------------------------
                                    551 ; absolute internal ram data
                                    552 ;--------------------------------------------------------
                                    553 	.area IABS    (ABS,DATA)
                                    554 	.area IABS    (ABS,DATA)
                                    555 ;--------------------------------------------------------
                                    556 ; bit data
                                    557 ;--------------------------------------------------------
                                    558 	.area BSEG    (BIT)
                                    559 ;--------------------------------------------------------
                                    560 ; paged external ram data
                                    561 ;--------------------------------------------------------
                                    562 	.area PSEG    (PAG,XDATA)
                                    563 ;--------------------------------------------------------
                                    564 ; uninitialized external ram data
                                    565 ;--------------------------------------------------------
                                    566 	.area XSEG    (XDATA)
                           00E400   567 _WAVEDATA	=	0xe400
                           00E600   568 _CPUCS	=	0xe600
                           00E601   569 _IFCONFIG	=	0xe601
                           00E602   570 _PINFLAGSAB	=	0xe602
                           00E603   571 _PINFLAGSCD	=	0xe603
                           00E604   572 _FIFORESET	=	0xe604
                           00E605   573 _BREAKPT	=	0xe605
                           00E606   574 _BPADDRH	=	0xe606
                           00E607   575 _BPADDRL	=	0xe607
                           00E608   576 _UART230	=	0xe608
                           00E609   577 _FIFOPINPOLAR	=	0xe609
                           00E60A   578 _REVID	=	0xe60a
                           00E60B   579 _REVCTL	=	0xe60b
                           00E60C   580 _GPIFHOLDAMOUNT	=	0xe60c
                           00E610   581 _EP1OUTCFG	=	0xe610
                           00E611   582 _EP1INCFG	=	0xe611
                           00E612   583 _EP2CFG	=	0xe612
                           00E613   584 _EP4CFG	=	0xe613
                           00E614   585 _EP6CFG	=	0xe614
                           00E615   586 _EP8CFG	=	0xe615
                           00E618   587 _EP2FIFOCFG	=	0xe618
                           00E619   588 _EP4FIFOCFG	=	0xe619
                           00E61A   589 _EP6FIFOCFG	=	0xe61a
                           00E61B   590 _EP8FIFOCFG	=	0xe61b
                           00E620   591 _EP2AUTOINLENH	=	0xe620
                           00E621   592 _EP2AUTOINLENL	=	0xe621
                           00E622   593 _EP4AUTOINLENH	=	0xe622
                           00E623   594 _EP4AUTOINLENL	=	0xe623
                           00E624   595 _EP6AUTOINLENH	=	0xe624
                           00E625   596 _EP6AUTOINLENL	=	0xe625
                           00E626   597 _EP8AUTOINLENH	=	0xe626
                           00E627   598 _EP8AUTOINLENL	=	0xe627
                           00E628   599 _ECCCFG	=	0xe628
                           00E629   600 _ECCRESET	=	0xe629
                           00E62A   601 _ECC1B0	=	0xe62a
                           00E62B   602 _ECC1B1	=	0xe62b
                           00E62C   603 _ECC1B2	=	0xe62c
                           00E62D   604 _ECC2B0	=	0xe62d
                           00E62E   605 _ECC2B1	=	0xe62e
                           00E62F   606 _ECC2B2	=	0xe62f
                           00E630   607 _EP2FIFOPFH	=	0xe630
                           00E631   608 _EP2FIFOPFL	=	0xe631
                           00E632   609 _EP4FIFOPFH	=	0xe632
                           00E633   610 _EP4FIFOPFL	=	0xe633
                           00E634   611 _EP6FIFOPFH	=	0xe634
                           00E635   612 _EP6FIFOPFL	=	0xe635
                           00E636   613 _EP8FIFOPFH	=	0xe636
                           00E637   614 _EP8FIFOPFL	=	0xe637
                           00E640   615 _EP2ISOINPKTS	=	0xe640
                           00E641   616 _EP4ISOINPKTS	=	0xe641
                           00E642   617 _EP6ISOINPKTS	=	0xe642
                           00E643   618 _EP8ISOINPKTS	=	0xe643
                           00E648   619 _INPKTEND	=	0xe648
                           00E649   620 _OUTPKTEND	=	0xe649
                           00E650   621 _EP2FIFOIE	=	0xe650
                           00E651   622 _EP2FIFOIRQ	=	0xe651
                           00E652   623 _EP4FIFOIE	=	0xe652
                           00E653   624 _EP4FIFOIRQ	=	0xe653
                           00E654   625 _EP6FIFOIE	=	0xe654
                           00E655   626 _EP6FIFOIRQ	=	0xe655
                           00E656   627 _EP8FIFOIE	=	0xe656
                           00E657   628 _EP8FIFOIRQ	=	0xe657
                           00E658   629 _IBNIE	=	0xe658
                           00E659   630 _IBNIRQ	=	0xe659
                           00E65A   631 _NAKIE	=	0xe65a
                           00E65B   632 _NAKIRQ	=	0xe65b
                           00E65C   633 _USBIE	=	0xe65c
                           00E65D   634 _USBIRQ	=	0xe65d
                           00E65E   635 _EPIE	=	0xe65e
                           00E65F   636 _EPIRQ	=	0xe65f
                           00E660   637 _GPIFIE	=	0xe660
                           00E661   638 _GPIFIRQ	=	0xe661
                           00E662   639 _USBERRIE	=	0xe662
                           00E663   640 _USBERRIRQ	=	0xe663
                           00E664   641 _ERRCNTLIM	=	0xe664
                           00E665   642 _CLRERRCNT	=	0xe665
                           00E666   643 _INT2IVEC	=	0xe666
                           00E667   644 _INT4IVEC	=	0xe667
                           00E668   645 _INTSETUP	=	0xe668
                           00E670   646 _PORTACFG	=	0xe670
                           00E671   647 _PORTCCFG	=	0xe671
                           00E672   648 _PORTECFG	=	0xe672
                           00E678   649 _I2CS	=	0xe678
                           00E679   650 _I2DAT	=	0xe679
                           00E67A   651 _I2CTL	=	0xe67a
                           00E67B   652 _XAUTODAT1	=	0xe67b
                           00E67C   653 _XAUTODAT2	=	0xe67c
                           00E67D   654 _UDMACRCH	=	0xe67d
                           00E67E   655 _UDMACRCL	=	0xe67e
                           00E67F   656 _UDMACRCQUAL	=	0xe67f
                           00E680   657 _USBCS	=	0xe680
                           00E681   658 _SUSPEND	=	0xe681
                           00E682   659 _WAKEUPCS	=	0xe682
                           00E683   660 _TOGCTL	=	0xe683
                           00E684   661 _USBFRAMEH	=	0xe684
                           00E685   662 _USBFRAMEL	=	0xe685
                           00E686   663 _MICROFRAME	=	0xe686
                           00E687   664 _FNADDR	=	0xe687
                           00E68A   665 _EP0BCH	=	0xe68a
                           00E68B   666 _EP0BCL	=	0xe68b
                           00E68D   667 _EP1OUTBC	=	0xe68d
                           00E68F   668 _EP1INBC	=	0xe68f
                           00E690   669 _EP2BCH	=	0xe690
                           00E691   670 _EP2BCL	=	0xe691
                           00E694   671 _EP4BCH	=	0xe694
                           00E695   672 _EP4BCL	=	0xe695
                           00E698   673 _EP6BCH	=	0xe698
                           00E699   674 _EP6BCL	=	0xe699
                           00E69C   675 _EP8BCH	=	0xe69c
                           00E69D   676 _EP8BCL	=	0xe69d
                           00E6A0   677 _EP0CS	=	0xe6a0
                           00E6A1   678 _EP1OUTCS	=	0xe6a1
                           00E6A2   679 _EP1INCS	=	0xe6a2
                           00E6A3   680 _EP2CS	=	0xe6a3
                           00E6A4   681 _EP4CS	=	0xe6a4
                           00E6A5   682 _EP6CS	=	0xe6a5
                           00E6A6   683 _EP8CS	=	0xe6a6
                           00E6A7   684 _EP2FIFOFLGS	=	0xe6a7
                           00E6A8   685 _EP4FIFOFLGS	=	0xe6a8
                           00E6A9   686 _EP6FIFOFLGS	=	0xe6a9
                           00E6AA   687 _EP8FIFOFLGS	=	0xe6aa
                           00E6AB   688 _EP2FIFOBCH	=	0xe6ab
                           00E6AC   689 _EP2FIFOBCL	=	0xe6ac
                           00E6AD   690 _EP4FIFOBCH	=	0xe6ad
                           00E6AE   691 _EP4FIFOBCL	=	0xe6ae
                           00E6AF   692 _EP6FIFOBCH	=	0xe6af
                           00E6B0   693 _EP6FIFOBCL	=	0xe6b0
                           00E6B1   694 _EP8FIFOBCH	=	0xe6b1
                           00E6B2   695 _EP8FIFOBCL	=	0xe6b2
                           00E6B3   696 _SUDPTRH	=	0xe6b3
                           00E6B4   697 _SUDPTRL	=	0xe6b4
                           00E6B5   698 _SUDPTRCTL	=	0xe6b5
                           00E6B8   699 _SETUPDAT	=	0xe6b8
                           00E6C0   700 _GPIFWFSELECT	=	0xe6c0
                           00E6C1   701 _GPIFIDLECS	=	0xe6c1
                           00E6C2   702 _GPIFIDLECTL	=	0xe6c2
                           00E6C3   703 _GPIFCTLCFG	=	0xe6c3
                           00E6C4   704 _GPIFADRH	=	0xe6c4
                           00E6C5   705 _GPIFADRL	=	0xe6c5
                           00E6C6   706 _FLOWSTATE	=	0xe6c6
                           00E6C7   707 _FLOWLOGIC	=	0xe6c7
                           00E6C8   708 _FLOWEQ0CTL	=	0xe6c8
                           00E6C9   709 _FLOWEQ1CTL	=	0xe6c9
                           00E6CA   710 _FLOWHOLDOFF	=	0xe6ca
                           00E6CB   711 _FLOWSTB	=	0xe6cb
                           00E6CC   712 _FLOWSTBEDGE	=	0xe6cc
                           00E6CD   713 _FLOWSTBHPERIOD	=	0xe6cd
                           00E6CE   714 _GPIFTCB3	=	0xe6ce
                           00E6CF   715 _GPIFTCB2	=	0xe6cf
                           00E6D0   716 _GPIFTCB1	=	0xe6d0
                           00E6D1   717 _GPIFTCB0	=	0xe6d1
                           00E6D2   718 _EP2GPIFFLGSEL	=	0xe6d2
                           00E6D3   719 _EP2GPIFPFSTOP	=	0xe6d3
                           00E6D4   720 _EP2GPIFTRIG	=	0xe6d4
                           00E6DA   721 _EP4GPIFFLGSEL	=	0xe6da
                           00E6DB   722 _EP4GPIFPFSTOP	=	0xe6db
                           00E6DC   723 _EP4GPIFTRIG	=	0xe6dc
                           00E6E2   724 _EP6GPIFFLGSEL	=	0xe6e2
                           00E6E3   725 _EP6GPIFPFSTOP	=	0xe6e3
                           00E6E4   726 _EP6GPIFTRIG	=	0xe6e4
                           00E6EA   727 _EP8GPIFFLGSEL	=	0xe6ea
                           00E6EB   728 _EP8GPIFPFSTOP	=	0xe6eb
                           00E6EC   729 _EP8GPIFTRIG	=	0xe6ec
                           00E6F0   730 _XGPIFSGLDATH	=	0xe6f0
                           00E6F1   731 _XGPIFSGLDATLX	=	0xe6f1
                           00E6F2   732 _XGPIFSGLDATLNOX	=	0xe6f2
                           00E6F3   733 _GPIFREADYCFG	=	0xe6f3
                           00E6F4   734 _GPIFREADYSTAT	=	0xe6f4
                           00E6F5   735 _GPIFABORT	=	0xe6f5
                           00E740   736 _EP0BUF	=	0xe740
                           00E780   737 _EP1OUTBUF	=	0xe780
                           00E7C0   738 _EP1INBUF	=	0xe7c0
                           00F000   739 _EP2FIFOBUF	=	0xf000
                           00F400   740 _EP4FIFOBUF	=	0xf400
                           00F800   741 _EP6FIFOBUF	=	0xf800
                           00FC00   742 _EP8FIFOBUF	=	0xfc00
                                    743 ;--------------------------------------------------------
                                    744 ; absolute external ram data
                                    745 ;--------------------------------------------------------
                                    746 	.area XABS    (ABS,XDATA)
                                    747 ;--------------------------------------------------------
                                    748 ; initialized external ram data
                                    749 ;--------------------------------------------------------
                                    750 	.area XISEG   (XDATA)
                                    751 	.area HOME    (CODE)
                                    752 	.area GSINIT0 (CODE)
                                    753 	.area GSINIT1 (CODE)
                                    754 	.area GSINIT2 (CODE)
                                    755 	.area GSINIT3 (CODE)
                                    756 	.area GSINIT4 (CODE)
                                    757 	.area GSINIT5 (CODE)
                                    758 	.area GSINIT  (CODE)
                                    759 	.area GSFINAL (CODE)
                                    760 	.area CSEG    (CODE)
                                    761 ;--------------------------------------------------------
                                    762 ; global & static initialisations
                                    763 ;--------------------------------------------------------
                                    764 	.area HOME    (CODE)
                                    765 	.area GSINIT  (CODE)
                                    766 	.area GSFINAL (CODE)
                                    767 	.area GSINIT  (CODE)
                                    768 ;--------------------------------------------------------
                                    769 ; Home
                                    770 ;--------------------------------------------------------
                                    771 	.area HOME    (CODE)
                                    772 	.area HOME    (CODE)
                                    773 ;--------------------------------------------------------
                                    774 ; code
                                    775 ;--------------------------------------------------------
                                    776 	.area CSEG    (CODE)
                                    777 ;------------------------------------------------------------
                                    778 ;Allocation info for local variables in function 'hid_report'
                                    779 ;------------------------------------------------------------
                                    780 ;size          Allocated to stack - _bp -5 +3 
                                    781 ;addr          Allocated to stack - _bp +1 +3 
                                    782 ;n             Allocated to registers r4 
                                    783 ;j             Allocated to stack - _bp +4 +1 
                                    784 ;------------------------------------------------------------
                                    785 ;	isr.c:16: void hid_report(const BYTE *addr, const BYTE *size) {
                                    786 ;	-----------------------------------------
                                    787 ;	 function hid_report
                                    788 ;	-----------------------------------------
      00041D                        789 _hid_report:
                           000007   790 	ar7 = 0x07
                           000006   791 	ar6 = 0x06
                           000005   792 	ar5 = 0x05
                           000004   793 	ar4 = 0x04
                           000003   794 	ar3 = 0x03
                           000002   795 	ar2 = 0x02
                           000001   796 	ar1 = 0x01
                           000000   797 	ar0 = 0x00
      00041D C0 1A            [24]  798 	push	_bp
      00041F 85 81 1A         [24]  799 	mov	_bp,sp
      000422 C0 82            [24]  800 	push	dpl
      000424 C0 83            [24]  801 	push	dph
      000426 C0 F0            [24]  802 	push	b
      000428 05 81            [12]  803 	inc	sp
                                    804 ;	isr.c:17: EP0BCH = 0;
      00042A 90 E6 8A         [24]  805 	mov	dptr,#_EP0BCH
      00042D E4               [12]  806 	clr	a
      00042E F0               [24]  807 	movx	@dptr,a
                                    808 ;	isr.c:18: BYTE n = 0;
      00042F FC               [12]  809 	mov	r4,a
                                    810 ;	isr.c:19: for (BYTE j = 0; j < size[0]; j++) {
      000430 E5 1A            [12]  811 	mov	a,_bp
      000432 24 FB            [12]  812 	add	a,#0xfb
      000434 F8               [12]  813 	mov	r0,a
      000435 86 02            [24]  814 	mov	ar2,@r0
      000437 08               [12]  815 	inc	r0
      000438 86 03            [24]  816 	mov	ar3,@r0
      00043A 08               [12]  817 	inc	r0
      00043B 86 07            [24]  818 	mov	ar7,@r0
      00043D E5 1A            [12]  819 	mov	a,_bp
      00043F 24 04            [12]  820 	add	a,#0x04
      000441 F8               [12]  821 	mov	r0,a
      000442 76 00            [12]  822 	mov	@r0,#0x00
      000444                        823 00108$:
      000444 8A 82            [24]  824 	mov	dpl,r2
      000446 8B 83            [24]  825 	mov	dph,r3
      000448 8F F0            [24]  826 	mov	b,r7
      00044A 12 06 40         [24]  827 	lcall	__gptrget
      00044D FD               [12]  828 	mov	r5,a
      00044E E5 1A            [12]  829 	mov	a,_bp
      000450 24 04            [12]  830 	add	a,#0x04
      000452 F8               [12]  831 	mov	r0,a
      000453 C3               [12]  832 	clr	c
      000454 E6               [12]  833 	mov	a,@r0
      000455 9D               [12]  834 	subb	a,r5
      000456 50 50            [24]  835 	jnc	00106$
                                    836 ;	isr.c:20: if (n == 64) { // MaxPacketSize
      000458 BC 40 0E         [24]  837 	cjne	r4,#0x40,00105$
                                    838 ;	isr.c:21: EP0BCL = n;
      00045B 90 E6 8B         [24]  839 	mov	dptr,#_EP0BCL
      00045E EC               [12]  840 	mov	a,r4
      00045F F0               [24]  841 	movx	@dptr,a
                                    842 ;	isr.c:22: n = 0;
      000460 7C 00            [12]  843 	mov	r4,#0x00
                                    844 ;	isr.c:23: while (EP0CS & b1); // BUSY
      000462                        845 00101$:
      000462 90 E6 A0         [24]  846 	mov	dptr,#_EP0CS
      000465 E0               [24]  847 	movx	a,@dptr
      000466 20 E1 F9         [24]  848 	jb	acc.1,00101$
      000469                        849 00105$:
                                    850 ;	isr.c:25: EP0BUF[n++] = addr[j];
      000469 C0 02            [24]  851 	push	ar2
      00046B C0 03            [24]  852 	push	ar3
      00046D C0 07            [24]  853 	push	ar7
      00046F 8C 05            [24]  854 	mov	ar5,r4
      000471 0C               [12]  855 	inc	r4
      000472 ED               [12]  856 	mov	a,r5
      000473 24 40            [12]  857 	add	a, #_EP0BUF
      000475 FD               [12]  858 	mov	r5,a
      000476 E4               [12]  859 	clr	a
      000477 34 E7            [12]  860 	addc	a, #(_EP0BUF >> 8)
      000479 FF               [12]  861 	mov	r7,a
      00047A A8 1A            [24]  862 	mov	r0,_bp
      00047C 08               [12]  863 	inc	r0
      00047D E5 1A            [12]  864 	mov	a,_bp
      00047F 24 04            [12]  865 	add	a,#0x04
      000481 F9               [12]  866 	mov	r1,a
      000482 E7               [12]  867 	mov	a,@r1
      000483 26               [12]  868 	add	a, @r0
      000484 FA               [12]  869 	mov	r2,a
      000485 E4               [12]  870 	clr	a
      000486 08               [12]  871 	inc	r0
      000487 36               [12]  872 	addc	a, @r0
      000488 FB               [12]  873 	mov	r3,a
      000489 08               [12]  874 	inc	r0
      00048A 86 06            [24]  875 	mov	ar6,@r0
      00048C 8A 82            [24]  876 	mov	dpl,r2
      00048E 8B 83            [24]  877 	mov	dph,r3
      000490 8E F0            [24]  878 	mov	b,r6
      000492 12 06 40         [24]  879 	lcall	__gptrget
      000495 8D 82            [24]  880 	mov	dpl,r5
      000497 8F 83            [24]  881 	mov	dph,r7
      000499 F0               [24]  882 	movx	@dptr,a
                                    883 ;	isr.c:19: for (BYTE j = 0; j < size[0]; j++) {
      00049A E5 1A            [12]  884 	mov	a,_bp
      00049C 24 04            [12]  885 	add	a,#0x04
      00049E F8               [12]  886 	mov	r0,a
      00049F 06               [12]  887 	inc	@r0
      0004A0 D0 07            [24]  888 	pop	ar7
      0004A2 D0 03            [24]  889 	pop	ar3
      0004A4 D0 02            [24]  890 	pop	ar2
      0004A6 80 9C            [24]  891 	sjmp	00108$
      0004A8                        892 00106$:
                                    893 ;	isr.c:27: EP0BCL = n;
      0004A8 90 E6 8B         [24]  894 	mov	dptr,#_EP0BCL
      0004AB EC               [12]  895 	mov	a,r4
      0004AC F0               [24]  896 	movx	@dptr,a
                                    897 ;	isr.c:28: }
      0004AD 85 1A 81         [24]  898 	mov	sp,_bp
      0004B0 D0 1A            [24]  899 	pop	_bp
      0004B2 22               [24]  900 	ret
                                    901 ;------------------------------------------------------------
                                    902 ;Allocation info for local variables in function 'isr'
                                    903 ;------------------------------------------------------------
                                    904 ;config        Allocated with name '_isr_config_30000_18'
                                    905 ;------------------------------------------------------------
                                    906 ;	isr.c:31: void isr(void) __interrupt(8) {
                                    907 ;	-----------------------------------------
                                    908 ;	 function isr
                                    909 ;	-----------------------------------------
      0004B3                        910 _isr:
      0004B3 C0 20            [24]  911 	push	bits
      0004B5 C0 E0            [24]  912 	push	acc
      0004B7 C0 F0            [24]  913 	push	b
      0004B9 C0 82            [24]  914 	push	dpl
      0004BB C0 83            [24]  915 	push	dph
      0004BD C0 07            [24]  916 	push	(0+7)
      0004BF C0 06            [24]  917 	push	(0+6)
      0004C1 C0 05            [24]  918 	push	(0+5)
      0004C3 C0 04            [24]  919 	push	(0+4)
      0004C5 C0 03            [24]  920 	push	(0+3)
      0004C7 C0 02            [24]  921 	push	(0+2)
      0004C9 C0 01            [24]  922 	push	(0+1)
      0004CB C0 00            [24]  923 	push	(0+0)
      0004CD C0 D0            [24]  924 	push	psw
      0004CF 75 D0 00         [24]  925 	mov	psw,#0x00
                                    926 ;	isr.c:32: if (USBIRQ & b4) { // URES
      0004D2 90 E6 5D         [24]  927 	mov	dptr,#_USBIRQ
      0004D5 E0               [24]  928 	movx	a,@dptr
      0004D6 30 E4 06         [24]  929 	jnb	acc.4,00102$
                                    930 ;	isr.c:33: USBIRQ = b4; // clear Usb RESet interrupt request
      0004D9 90 E6 5D         [24]  931 	mov	dptr,#_USBIRQ
      0004DC 74 10            [12]  932 	mov	a,#0x10
      0004DE F0               [24]  933 	movx	@dptr,a
      0004DF                        934 00102$:
                                    935 ;	isr.c:35: if (USBIRQ & b0) { // SETUP
      0004DF 90 E6 5D         [24]  936 	mov	dptr,#_USBIRQ
      0004E2 E0               [24]  937 	movx	a,@dptr
      0004E3 20 E0 03         [24]  938 	jb	acc.0,00217$
      0004E6 02 06 23         [24]  939 	ljmp	00130$
      0004E9                        940 00217$:
                                    941 ;	isr.c:36: if (SETUPDAT[1] == 6) { // GET_DESCRIPTOR
      0004E9 90 E6 B9         [24]  942 	mov	dptr,#(_SETUPDAT + 0x0001)
      0004EC E0               [24]  943 	movx	a,@dptr
      0004ED FF               [12]  944 	mov	r7,a
      0004EE BF 06 02         [24]  945 	cjne	r7,#0x06,00218$
      0004F1 80 03            [24]  946 	sjmp	00219$
      0004F3                        947 00218$:
      0004F3 02 05 E7         [24]  948 	ljmp	00126$
      0004F6                        949 00219$:
                                    950 ;	isr.c:37: switch (SETUPDAT[3]) {
      0004F6 90 E6 BB         [24]  951 	mov	dptr,#(_SETUPDAT + 0x0003)
      0004F9 E0               [24]  952 	movx	a,@dptr
      0004FA FF               [12]  953 	mov	r7,a
      0004FB BF 01 02         [24]  954 	cjne	r7,#0x01,00220$
      0004FE 80 1E            [24]  955 	sjmp	00103$
      000500                        956 00220$:
      000500 BF 02 02         [24]  957 	cjne	r7,#0x02,00221$
      000503 80 2B            [24]  958 	sjmp	00104$
      000505                        959 00221$:
      000505 BF 03 02         [24]  960 	cjne	r7,#0x03,00222$
      000508 80 38            [24]  961 	sjmp	00105$
      00050A                        962 00222$:
      00050A BF 06 03         [24]  963 	cjne	r7,#0x06,00223$
      00050D 02 05 DD         [24]  964 	ljmp	00117$
      000510                        965 00223$:
      000510 BF 07 03         [24]  966 	cjne	r7,#0x07,00224$
      000513 02 05 DD         [24]  967 	ljmp	00117$
      000516                        968 00224$:
      000516 BF 22 02         [24]  969 	cjne	r7,#0x22,00225$
      000519 80 72            [24]  970 	sjmp	00108$
      00051B                        971 00225$:
      00051B 02 05 DD         [24]  972 	ljmp	00117$
                                    973 ;	isr.c:38: case 0x01: // DEVICE
      00051E                        974 00103$:
                                    975 ;	isr.c:39: SUDPTRH = MSB(DeviceDscr);
      00051E 7E 00            [12]  976 	mov	r6,#_DeviceDscr
      000520 7F 3E            [12]  977 	mov	r7,#(_DeviceDscr >> 8)
      000522 90 E6 B3         [24]  978 	mov	dptr,#_SUDPTRH
      000525 EF               [12]  979 	mov	a,r7
      000526 F0               [24]  980 	movx	@dptr,a
                                    981 ;	isr.c:40: SUDPTRL = LSB(DeviceDscr); // &0xFE
      000527 90 E6 B4         [24]  982 	mov	dptr,#_SUDPTRL
      00052A 74 00            [12]  983 	mov	a,#_DeviceDscr
      00052C F0               [24]  984 	movx	@dptr,a
                                    985 ;	isr.c:41: break;
      00052D 02 06 15         [24]  986 	ljmp	00127$
                                    987 ;	isr.c:42: case 0x02: // CONFIGURATION
      000530                        988 00104$:
                                    989 ;	isr.c:43: SUDPTRH = MSB(ConfigDscr);
      000530 7E 12            [12]  990 	mov	r6,#_ConfigDscr
      000532 7F 3E            [12]  991 	mov	r7,#(_ConfigDscr >> 8)
      000534 90 E6 B3         [24]  992 	mov	dptr,#_SUDPTRH
      000537 EF               [12]  993 	mov	a,r7
      000538 F0               [24]  994 	movx	@dptr,a
                                    995 ;	isr.c:44: SUDPTRL = LSB(ConfigDscr); // &0xFE
      000539 90 E6 B4         [24]  996 	mov	dptr,#_SUDPTRL
      00053C 74 12            [12]  997 	mov	a,#_ConfigDscr
      00053E F0               [24]  998 	movx	@dptr,a
                                    999 ;	isr.c:45: break;
      00053F 02 06 15         [24] 1000 	ljmp	00127$
                                   1001 ;	isr.c:46: case 0x03: // STRING
      000542                       1002 00105$:
                                   1003 ;	isr.c:47: if (SETUPDAT[2] >= sizeof(StringDscr)/sizeof(BYTE*)) {
      000542 90 E6 BA         [24] 1004 	mov	dptr,#(_SETUPDAT + 0x0002)
      000545 E0               [24] 1005 	movx	a,@dptr
      000546 FF               [12] 1006 	mov	r7,a
      000547 BF 03 00         [24] 1007 	cjne	r7,#0x03,00226$
      00054A                       1008 00226$:
      00054A 40 0B            [24] 1009 	jc	00107$
                                   1010 ;	isr.c:48: EP0CS |= b0; // STALL
      00054C 90 E6 A0         [24] 1011 	mov	dptr,#_EP0CS
      00054F E0               [24] 1012 	movx	a,@dptr
      000550 43 E0 01         [24] 1013 	orl	acc,#0x01
      000553 F0               [24] 1014 	movx	@dptr,a
                                   1015 ;	isr.c:49: break;
      000554 02 06 15         [24] 1016 	ljmp	00127$
      000557                       1017 00107$:
                                   1018 ;	isr.c:51: SUDPTRH = MSB(StringDscr[SETUPDAT[2]]);
      000557 90 E6 BA         [24] 1019 	mov	dptr,#(_SETUPDAT + 0x0002)
      00055A E0               [24] 1020 	movx	a,@dptr
      00055B 75 F0 03         [24] 1021 	mov	b,#0x03
      00055E A4               [48] 1022 	mul	ab
      00055F 24 60            [12] 1023 	add	a, #_StringDscr
      000561 F5 82            [12] 1024 	mov	dpl,a
      000563 74 06            [12] 1025 	mov	a,#(_StringDscr >> 8)
      000565 35 F0            [12] 1026 	addc	a, b
      000567 F5 83            [12] 1027 	mov	dph,a
      000569 E4               [12] 1028 	clr	a
      00056A 93               [24] 1029 	movc	a,@a+dptr
      00056B A3               [24] 1030 	inc	dptr
      00056C E4               [12] 1031 	clr	a
      00056D 93               [24] 1032 	movc	a,@a+dptr
      00056E 90 E6 B3         [24] 1033 	mov	dptr,#_SUDPTRH
      000571 F0               [24] 1034 	movx	@dptr,a
                                   1035 ;	isr.c:52: SUDPTRL = LSB(StringDscr[SETUPDAT[2]]); // &0xFE
      000572 90 E6 BA         [24] 1036 	mov	dptr,#(_SETUPDAT + 0x0002)
      000575 E0               [24] 1037 	movx	a,@dptr
      000576 75 F0 03         [24] 1038 	mov	b,#0x03
      000579 A4               [48] 1039 	mul	ab
      00057A 24 60            [12] 1040 	add	a, #_StringDscr
      00057C F5 82            [12] 1041 	mov	dpl,a
      00057E 74 06            [12] 1042 	mov	a,#(_StringDscr >> 8)
      000580 35 F0            [12] 1043 	addc	a, b
      000582 F5 83            [12] 1044 	mov	dph,a
      000584 E4               [12] 1045 	clr	a
      000585 93               [24] 1046 	movc	a,@a+dptr
      000586 90 E6 B4         [24] 1047 	mov	dptr,#_SUDPTRL
      000589 F0               [24] 1048 	movx	@dptr,a
                                   1049 ;	isr.c:53: break;
      00058A 02 06 15         [24] 1050 	ljmp	00127$
                                   1051 ;	isr.c:54: case 0x22: // HID_REPORT
      00058D                       1052 00108$:
                                   1053 ;	isr.c:55: if (SETUPDAT[4] == 0) {
      00058D 90 E6 BC         [24] 1054 	mov	dptr,#(_SETUPDAT + 0x0004)
      000590 E0               [24] 1055 	movx	a,@dptr
      000591 70 1C            [24] 1056 	jnz	00113$
                                   1057 ;	isr.c:56: hid_report(ReportDscr_Mouse, ReportDscrSize_Mouse);
      000593 74 2B            [12] 1058 	mov	a,#_ReportDscrSize_Mouse
      000595 C0 E0            [24] 1059 	push	acc
      000597 74 3E            [12] 1060 	mov	a,#(_ReportDscrSize_Mouse >> 8)
      000599 C0 E0            [24] 1061 	push	acc
      00059B 74 80            [12] 1062 	mov	a,#0x80
      00059D C0 E0            [24] 1063 	push	acc
      00059F 90 3E 4E         [24] 1064 	mov	dptr,#_ReportDscr_Mouse
      0005A2 F5 F0            [12] 1065 	mov	b,a
      0005A4 12 04 1D         [24] 1066 	lcall	_hid_report
      0005A7 15 81            [12] 1067 	dec	sp
      0005A9 15 81            [12] 1068 	dec	sp
      0005AB 15 81            [12] 1069 	dec	sp
      0005AD 80 66            [24] 1070 	sjmp	00127$
      0005AF                       1071 00113$:
                                   1072 ;	isr.c:57: } else if (SETUPDAT[4] == 1) {
      0005AF 90 E6 BC         [24] 1073 	mov	dptr,#(_SETUPDAT + 0x0004)
      0005B2 E0               [24] 1074 	movx	a,@dptr
      0005B3 FF               [12] 1075 	mov	r7,a
      0005B4 BF 01 1C         [24] 1076 	cjne	r7,#0x01,00110$
                                   1077 ;	isr.c:58: hid_report(ReportDscr_Keyboard, ReportDscrSize_Keyboard);
      0005B7 74 44            [12] 1078 	mov	a,#_ReportDscrSize_Keyboard
      0005B9 C0 E0            [24] 1079 	push	acc
      0005BB 74 3E            [12] 1080 	mov	a,#(_ReportDscrSize_Keyboard >> 8)
      0005BD C0 E0            [24] 1081 	push	acc
      0005BF 74 80            [12] 1082 	mov	a,#0x80
      0005C1 C0 E0            [24] 1083 	push	acc
      0005C3 90 3E 80         [24] 1084 	mov	dptr,#_ReportDscr_Keyboard
      0005C6 F5 F0            [12] 1085 	mov	b,a
      0005C8 12 04 1D         [24] 1086 	lcall	_hid_report
      0005CB 15 81            [12] 1087 	dec	sp
      0005CD 15 81            [12] 1088 	dec	sp
      0005CF 15 81            [12] 1089 	dec	sp
      0005D1 80 42            [24] 1090 	sjmp	00127$
      0005D3                       1091 00110$:
                                   1092 ;	isr.c:60: EP0CS |= b0; // STALL
      0005D3 90 E6 A0         [24] 1093 	mov	dptr,#_EP0CS
      0005D6 E0               [24] 1094 	movx	a,@dptr
      0005D7 43 E0 01         [24] 1095 	orl	acc,#0x01
      0005DA F0               [24] 1096 	movx	@dptr,a
                                   1097 ;	isr.c:62: break;
                                   1098 ;	isr.c:67: default:
      0005DB 80 38            [24] 1099 	sjmp	00127$
      0005DD                       1100 00117$:
                                   1101 ;	isr.c:68: EP0CS |= b0; // STALL
      0005DD 90 E6 A0         [24] 1102 	mov	dptr,#_EP0CS
      0005E0 E0               [24] 1103 	movx	a,@dptr
      0005E1 43 E0 01         [24] 1104 	orl	acc,#0x01
      0005E4 F0               [24] 1105 	movx	@dptr,a
                                   1106 ;	isr.c:69: }
      0005E5 80 2E            [24] 1107 	sjmp	00127$
      0005E7                       1108 00126$:
                                   1109 ;	isr.c:71: else if (SETUPDAT[1] == 8) { // GET_CONFIGURATION
      0005E7 90 E6 B9         [24] 1110 	mov	dptr,#(_SETUPDAT + 0x0001)
      0005EA E0               [24] 1111 	movx	a,@dptr
      0005EB FF               [12] 1112 	mov	r7,a
      0005EC BF 08 12         [24] 1113 	cjne	r7,#0x08,00123$
                                   1114 ;	isr.c:72: EP0BUF[0] = 1;
      0005EF 90 E7 40         [24] 1115 	mov	dptr,#_EP0BUF
      0005F2 74 01            [12] 1116 	mov	a,#0x01
      0005F4 F0               [24] 1117 	movx	@dptr,a
                                   1118 ;	isr.c:73: EP0BCH = 0;
      0005F5 90 E6 8A         [24] 1119 	mov	dptr,#_EP0BCH
      0005F8 E4               [12] 1120 	clr	a
      0005F9 F0               [24] 1121 	movx	@dptr,a
                                   1122 ;	isr.c:74: EP0BCL = 1;
      0005FA 90 E6 8B         [24] 1123 	mov	dptr,#_EP0BCL
      0005FD 04               [12] 1124 	inc	a
      0005FE F0               [24] 1125 	movx	@dptr,a
      0005FF 80 14            [24] 1126 	sjmp	00127$
      000601                       1127 00123$:
                                   1128 ;	isr.c:76: else if (SETUPDAT[1] == 9) { // SET_CONFIGURATION
      000601 90 E6 B9         [24] 1129 	mov	dptr,#(_SETUPDAT + 0x0001)
      000604 E0               [24] 1130 	movx	a,@dptr
      000605 FF               [12] 1131 	mov	r7,a
      000606 BF 09 08         [24] 1132 	cjne	r7,#0x09,00120$
                                   1133 ;	isr.c:78: config = EP0BUF[2];
      000609 90 E7 42         [24] 1134 	mov	dptr,#(_EP0BUF + 0x0002)
      00060C E0               [24] 1135 	movx	a,@dptr
      00060D F5 19            [12] 1136 	mov	_isr_config_30000_18,a
      00060F 80 04            [24] 1137 	sjmp	00127$
      000611                       1138 00120$:
                                   1139 ;	isr.c:80: else if (SETUPDAT[1] == 10) { // GET_INTERFACE
      000611 90 E6 B9         [24] 1140 	mov	dptr,#(_SETUPDAT + 0x0001)
      000614 E0               [24] 1141 	movx	a,@dptr
      000615                       1142 00127$:
                                   1143 ;	isr.c:84: EP0CS |= b7; // HSNAK (automatically handshake NAKs)
      000615 90 E6 A0         [24] 1144 	mov	dptr,#_EP0CS
      000618 E0               [24] 1145 	movx	a,@dptr
      000619 43 E0 80         [24] 1146 	orl	acc,#0x80
      00061C F0               [24] 1147 	movx	@dptr,a
                                   1148 ;	isr.c:85: USBIRQ = b0; // SUDAV (SETUP Data Available)
      00061D 90 E6 5D         [24] 1149 	mov	dptr,#_USBIRQ
      000620 74 01            [12] 1150 	mov	a,#0x01
      000622 F0               [24] 1151 	movx	@dptr,a
      000623                       1152 00130$:
                                   1153 ;	isr.c:87: }
      000623 D0 D0            [24] 1154 	pop	psw
      000625 D0 00            [24] 1155 	pop	(0+0)
      000627 D0 01            [24] 1156 	pop	(0+1)
      000629 D0 02            [24] 1157 	pop	(0+2)
      00062B D0 03            [24] 1158 	pop	(0+3)
      00062D D0 04            [24] 1159 	pop	(0+4)
      00062F D0 05            [24] 1160 	pop	(0+5)
      000631 D0 06            [24] 1161 	pop	(0+6)
      000633 D0 07            [24] 1162 	pop	(0+7)
      000635 D0 83            [24] 1163 	pop	dph
      000637 D0 82            [24] 1164 	pop	dpl
      000639 D0 F0            [24] 1165 	pop	b
      00063B D0 E0            [24] 1166 	pop	acc
      00063D D0 20            [24] 1167 	pop	bits
      00063F 32               [24] 1168 	reti
                                   1169 	.area CSEG    (CODE)
                                   1170 	.area CONST   (CODE)
                                   1171 	.area CONST   (CODE)
      000660                       1172 _StringDscr:
      000660 C0 3E 80              1173 	.byte _str0, (_str0 >> 8),#0x80
      000663 C4 3E 80              1174 	.byte _str1, (_str1 >> 8),#0x80
      000666 D4 3E 80              1175 	.byte _str2, (_str2 >> 8),#0x80
                                   1176 	.area CSEG    (CODE)
                                   1177 	.area XINIT   (CODE)
                                   1178 	.area CABS    (ABS,CODE)
