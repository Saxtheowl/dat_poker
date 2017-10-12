#include "poker_defs.h"

/* 
 * Table StdDeck_cardMasksTable
 */

/*
StdDeck_cardMasks[].  Maps card indices (0..51) to CardMasks.  
The output mask has only one bit set, the bit corresponding to the card
identified by the index.
 */

StdDeck_CardMask StdDeck_cardMasksTable[52] = { 
      { 0x0001000000000000 }  ,
      { 0x0002000000000000 }  ,
      { 0x0004000000000000 }  ,
      { 0x0008000000000000 }  ,
      { 0x0010000000000000 }  ,
      { 0x0020000000000000 }  ,
      { 0x0040000000000000 }  ,
      { 0x0080000000000000 }  ,
      { 0x0100000000000000 }  ,
      { 0x0200000000000000 }  ,
      { 0x0400000000000000 }  ,
      { 0x0800000000000000 }  ,
      { 0x1000000000000000 }  ,
      { 0x0000000100000000 }  ,
      { 0x0000000200000000 }  ,
      { 0x0000000400000000 }  ,
      { 0x0000000800000000 }  ,
      { 0x0000001000000000 }  ,
      { 0x0000002000000000 }  ,
      { 0x0000004000000000 }  ,
      { 0x0000008000000000 }  ,
      { 0x0000010000000000 }  ,
      { 0x0000020000000000 }  ,
      { 0x0000040000000000 }  ,
      { 0x0000080000000000 }  ,
      { 0x0000100000000000 }  ,
      { 0x0000000000010000 }  ,
      { 0x0000000000020000 }  ,
      { 0x0000000000040000 }  ,
      { 0x0000000000080000 }  ,
      { 0x0000000000100000 }  ,
      { 0x0000000000200000 }  ,
      { 0x0000000000400000 }  ,
      { 0x0000000000800000 }  ,
      { 0x0000000001000000 }  ,
      { 0x0000000002000000 }  ,
      { 0x0000000004000000 }  ,
      { 0x0000000008000000 }  ,
      { 0x0000000010000000 }  ,
      { 0x0000000000000001 }  ,
      { 0x0000000000000002 }  ,
      { 0x0000000000000004 }  ,
      { 0x0000000000000008 }  ,
      { 0x0000000000000010 }  ,
      { 0x0000000000000020 }  ,
      { 0x0000000000000040 }  ,
      { 0x0000000000000080 }  ,
      { 0x0000000000000100 }  ,
      { 0x0000000000000200 }  ,
      { 0x0000000000000400 }  ,
      { 0x0000000000000800 }  ,
      { 0x0000000000001000 }  
};
