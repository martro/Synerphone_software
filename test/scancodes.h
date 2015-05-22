// scancodes.h
//  http://radzio.dxp.pl
#ifndef SCANCODES_H_
#define SCANCODES_H_
# include <avr/pgmspace.h>

static unsigned char PROGMEM scancodes[] = {
/*
ASCII   SCANCODE   KLAWISZ
*/
// bez SHIFT
0x00, // 0x00      BRAK
0x00, //    1      F9
0x00, //    2
0x00, //    3      F5
0x00, //    4      F3
0xC8, //    5      F1
0x00, //    6      F2
0x00, //    7      F12
0x00, //    8
0x00, //    9      F10
0x00, //    A      F8
0x00, //    B      F6
0x00, //    C      F4
0x00, //    D
0x5E, //    E
0x00, //    F
0x00, // 0x10
0x00, //    1
0x00, //    2
0x00, //    3
0x00, //    4
0x71, //    5      q
0x31, //    6      1
0x00, //    7
0x00, //    8
0x00, //    9
0x7A, //    A      z
0x73, //    B      s
0x61, //    C      a
0x77, //    D      w
0x32, //    E      2
0x00, //    F
0x00, // 0x20
0x63, //    1      c
0x78, //    2      x
0x64, //    3      d
0x65, //    4      e
0x34, //    5      4
0x33, //    6      3
0x00, //    7
0x00, //    8
0x20, //    9      SPACE
0x76, //    A      v
0x66, //    B      f
0x74, //    C      t
0x72, //    D      r
0x35, //    E      5
0x00, //    F
0x00, // 0x30
0x6E, //    1      n
0x62, //    2      b
0x68, //    3      h
0x67, //    4      g
0x79, //    5      y
0x36, //    6      6
0x07, //    7
0x08, //    8
0x2C, //    9
0x6D, //    A      m
0x6A, //    B      j
0x75, //    C      u
0x37, //    D      7
0x38, //    E      8
0x00, //    F
0x00, // 0x40
0x2C, //    1      ,
0x6B, //    2      k
0x69, //    3      i
0x6F, //    4      o
0x30, //    5      0
0x39, //    6      9
0x00, //    7
0x00, //    8
0x2E, //    9      .
0x2F, //    A      /
0x6C, //    B      l
0x3B, //    C      ;
0x70, //    D      p
0x2D, //    E      -
0x00, //    F
0x00, // 0x50
0x00, //    1
0x60, //    2      '
0x00, //    3
0x5B, //    4      [
0x3D, //    5      =
0x00, //    6
0x00, //    7
0x00, //    8
0x00, //    9
0x0D, //    A
0x5D, //    B      ]
0x00, //    C
0x5C, //    D      \
0x00, //    E
0x00, //    F
0x00, // 0x60
0x3C, //    1
0x00, //    2
0x00, //    3
0x00, //    4
0x00, //    5
0x08, //    6
0x00, //    7
0x00, //    8
0x31, //    9
0x00, //    A
0x34, //    B
0x37, //    C
0x00, //    D
0x00, //    E
0x00, //    F
0x30, // 0x70
0x2C, //    1
0x32, //    2
0x35, //    3
0x36, //    4
0x38, //    5
0x00, //    6
0x00, //    7
0x00, //    8
0x2B, //    9
0x33, //    A
0x2D, //    B
0x2A, //    C
0x39, //    D
0x00, //    E
0x00, //    F
0x00,
// z SHIFT
0x00, // 0x00      BRAK
0x00, //    1      F9
0x00, //    2
0x00, //    3      F5
0x00, //    4      F3
0xC8, //    5      F1
0x00, //    6      F2
0x00, //    7      F12
0x00, //    8
0x00, //    9      F10
0x00, //    A      F8
0x00, //    B      F6
0x00, //    C      F4
0x00, //    D
0x5E, //    E
0x00, //    F
0x00, // 0x10
0x00, //    1
0x00, //    2
0x00, //    3
0x00, //    4
0x51, //    5      Q
0x21, //    6      !
0x00, //    7
0x00, //    8
0x00, //    9
0x5A, //    A      Z
0x53, //    B      S
0x41, //    C      A
0x57, //    D      W
0x40, //    E      @
0x00, //    F
0x00, // 0x20
0x43, //    1      C
0x58, //    2      X
0x44, //    3      D
0x45, //    4      E
0x24, //    5      $
0x23, //    6      #
0x00, //    7
0x00, //    8
0x20, //    9      SPACE
0x56, //    A      V
0x46, //    B      F
0x54, //    C      T
0x52, //    D      R
0x25, //    E      %
0x00, //    F
0x00, // 0x30
0x4E, //    1      N
0x42, //    2      B
0x48, //    3      H
0x47, //    4      G
0x59, //    5      Y
0x5E, //    6      ^
0x07, //    7
0x08, //    8
0x2C, //    9
0x4D, //    A      M
0x4A, //    B      J
0x55, //    C      U
0x26, //    D      &
0x2A, //    E      *
0x00, //    F
0x00, // 0x40
0x3C, //    1      <
0x4B, //    2      K
0x49, //    3      I
0x4F, //    4      O
0x29, //    5      )
0x28, //    6      (
0x00, //    7
0x00, //    8
0x3E, //    9      >
0x3F, //    A      ?
0x4C, //    B      L
0x3A, //    C      :
0x50, //    D      P
0x2D, //    E      _
0x00, //    F
0x00, // 0x50
0x00, //    1
0x22, //    2      "
0x00, //    3
0x7B, //    4      {
0x3D, //    5      +
0x00, //    6
0x00, //    7
0x00, //    8
0x00, //    9
0x0D, //    A
0x7D, //    B      }
0x00, //    C
0x7C, //    D      |
0x00, //    E
0x00, //    F
0x00, // 0x60
0x3C, //    1
0x00, //    2
0x00, //    3
0x00, //    4
0x00, //    5
0x08, //    6
0x00, //    7
0x00, //    8
0x31, //    9
0x00, //    A
0x34, //    B
0x37, //    C
0x00, //    D
0x00, //    E
0x00, //    F
0x30, // 0x70
0x2C, //    1
0x32, //    2
0x35, //    3
0x36, //    4
0x38, //    5
0x00, //    6
0x00, //    7
0x00, //    8
0x2B, //    9
0x33, //    A
0x2D, //    B
0x2A, //    C
0x39, //    D
0x00, //    E
0x00, //    F
};
//

#endif /* SCANCODES_H_ */