// Copyright (C) 2021 Arno Ansems
// 
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with this program.  If not, see http://www.gnu.org/licenses/ 

#include "SavedGameInDosFormat_Test.h"
#include "../Engine/SavedGameInDosFormat.h"

static const uint8_t rawSavedGameData[3166] =
{
    0x43, 0x33, 0x44, 0x00, 0x0C, 0xA5, 0x00, 0x00, 0x6C, 0x65, 0x76, 0x65, 0x6C, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x05, 0x00, 0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9C, 0x31, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x3E, 0x04, 0xCD, 0xAB, 0x20, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0x02, 0x00, 0x01, 0x00,
    0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0xCD, 0xAB, 0x0C, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x0C, 0x00, 0xB9, 0x00, 0xB4, 0x00,
    0xCD, 0xAB, 0x06, 0x00, 0xBA, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0x01, 0x00, 0xCD, 0xAB,
    0x0A, 0x00, 0xB8, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x0C, 0x00, 0xB9, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBA, 0x00,
    0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x0A, 0x00, 0xB8, 0x00, 0xB4, 0x00,
    0xCD, 0xAB, 0x0C, 0x00, 0xB9, 0x00, 0x02, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBA, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB,
    0x07, 0x00, 0xBC, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x0C, 0x00,
    0xB9, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0xB4, 0x00, 0xCD, 0xAB,
    0x09, 0x00, 0xB8, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCD, 0xAB, 0x08, 0x00,
    0x02, 0x00, 0x04, 0x00, 0xC1, 0x00, 0xC1, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xBC, 0x00, 0x02, 0x00, 0x01, 0x00,
    0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB8, 0x00, 0x01, 0x00, 0x02, 0x00, 0xCD, 0xAB,
    0x0F, 0x00, 0xC1, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00,
    0xBC, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB8, 0x00, 0x01, 0x00, 0x02, 0x00, 0xCD, 0xAB, 0x0F, 0x00, 0xC1, 0x00,
    0x02, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0x01, 0x00,
    0xCD, 0xAB, 0x09, 0x00, 0xB8, 0x00, 0x01, 0x00, 0x02, 0x00, 0xCD, 0xAB, 0x0F, 0x00, 0xC1, 0x00, 0x04, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00,
    0xB4, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x14, 0x00, 0x14, 0x00,
    0x14, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x02, 0x00, 0x04, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0x02, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0x02, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0xBC, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xB6, 0x00,
    0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00, 0xB7, 0x00, 0xB7, 0x00, 0xB7, 0x00, 0xCD, 0xAB, 0x0C, 0x00, 0x01, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0x02, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB6, 0x00, 0xB4, 0x00,
    0xCD, 0xAB, 0x09, 0x00, 0xB7, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xCD, 0xAB,
    0x0E, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB6, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB7, 0x00, 0xCD, 0xAB,
    0x04, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00,
    0x01, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xB5, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xB6, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB,
    0x05, 0x00, 0xB7, 0x00, 0x03, 0x00, 0x03, 0x00, 0xB7, 0x00, 0xB7, 0x00, 0x20, 0x00, 0xBD, 0x00, 0xBD, 0x00, 0x01, 0x00,
    0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB,
    0x08, 0x00, 0xB5, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xB6, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xB7, 0x00,
    0x03, 0x00, 0xB7, 0x00, 0xB7, 0x00, 0x20, 0x00, 0xBD, 0x00, 0xB4, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00,
    0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xB5, 0x00, 0xCD, 0xAB,
    0x08, 0x00, 0xB6, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x05, 0x00, 0xB7, 0x00, 0x03, 0x00, 0x03, 0x00, 0xB7, 0x00,
    0xB7, 0x00, 0x20, 0x00, 0xBD, 0x00, 0xBD, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBE, 0x00,
    0xBE, 0x00, 0xBE, 0x00, 0xCD, 0xAB, 0x0A, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB6, 0x00, 0xB4, 0x00, 0xCD, 0xAB,
    0x09, 0x00, 0xB7, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBE, 0x00,
    0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0x03, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x09, 0x00,
    0xB6, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x09, 0x00, 0xB7, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBE, 0x00, 0x01, 0x00,
    0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0xC2, 0x00, 0xC0, 0x00,
    0x03, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xB6, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00, 0xB7, 0x00, 0xB7, 0x00,
    0xB7, 0x00, 0xCD, 0xAB, 0x05, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00,
    0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0xC2, 0x00, 0xC0, 0x00, 0x03, 0x00, 0xCD, 0xAB,
    0x04, 0x00, 0x01, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0x01, 0x00, 0xB4, 0x00, 0xB4, 0x00,
    0xB4, 0x00, 0xCD, 0xAB, 0x05, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00,
    0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0xC2, 0x00, 0xC0, 0x00, 0xCD, 0xAB,
    0x05, 0x00, 0x03, 0x00, 0xBB, 0x00, 0xBB, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x03, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x0E, 0x00,
    0xBE, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x03, 0x00, 0x03, 0x00,
    0xBB, 0x00, 0xBB, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x03, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x01, 0x00,
    0xCD, 0xAB, 0x0E, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x03, 0x00, 0xCD, 0xAB,
    0x0F, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x0E, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00,
    0xBE, 0x00, 0x01, 0x00, 0x03, 0x00, 0xCD, 0xAB, 0x0F, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x01, 0x00, 0xBE, 0x00, 0xBE, 0x00,
    0xBE, 0x00, 0xCD, 0xAB, 0x0C, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x06, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x03, 0x00, 0xCD, 0xAB,
    0x0F, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x12, 0x00, 0xBE, 0x00, 0x01, 0x00, 0x01, 0x00, 0x08, 0x00,
    0x01, 0x00, 0x03, 0x00, 0xCD, 0xAB, 0x0F, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x01, 0x00, 0xCD, 0xAB, 0x12, 0x00, 0xBE, 0x00,
    0x01, 0x00, 0xBF, 0x00, 0xBF, 0x00, 0x02, 0x00, 0x03, 0x00, 0xCD, 0xAB, 0x0F, 0x00, 0xBB, 0x00, 0x03, 0x00, 0x01, 0x00,
    0xCD, 0xAB, 0x12, 0x00, 0xBE, 0x00, 0x01, 0x00, 0xBC, 0x00, 0xBF, 0x00, 0x02, 0x00, 0xCD, 0xAB, 0x11, 0x00, 0x03, 0x00,
    0xCD, 0xAB, 0x14, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x68, 0x01, 0xCD, 0xAB, 0x46, 0x00, 0x00, 0x00,
    0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0xCD, 0xAB, 0x10, 0x00, 0x00, 0x00,
    0x17, 0x00, 0xCD, 0xAB, 0x0D, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0xCD, 0xAB, 0x34, 0x00, 0x00, 0x00, 0x17, 0x00,
    0xCD, 0xAB, 0x42, 0x00, 0x00, 0x00, 0x05, 0x00, 0xCD, 0xAB, 0x05, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x0B, 0x00,
    0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x0D, 0x00, 0x00, 0x00, 0x16, 0x00, 0xCD, 0xAB, 0x07, 0x00, 0x00, 0x00, 0x05, 0x00,
    0xCD, 0xAB, 0x18, 0x00, 0x00, 0x00, 0x16, 0x00, 0xCD, 0xAB, 0x16, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x1D, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xCD, 0xAB, 0x25, 0x00, 0x00, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00,
    0xCD, 0xAB, 0x25, 0x00, 0x00, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0xCD, 0xAB, 0x0E, 0x00, 0x00, 0x00, 0x17, 0x00,
    0xCD, 0xAB, 0x12, 0x00, 0x00, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0xCD, 0xAB, 0x25, 0x00, 0x00, 0x00, 0x15, 0x00,
    0x15, 0x00, 0x15, 0x00, 0x00, 0x00, 0x0B, 0x00, 0xCD, 0xAB, 0x23, 0x00, 0x00, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0xCD, 0xAB, 0x05, 0x00, 0x00, 0x00,
    0x17, 0x00, 0xCD, 0xAB, 0x15, 0x00, 0x00, 0x00, 0x18, 0x00, 0xCD, 0xAB, 0x52, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB,
    0x30, 0x00, 0x00, 0x00, 0xCD, 0xAB, 0x05, 0x00, 0x15, 0x00, 0xCD, 0xAB, 0x23, 0x00, 0x00, 0x00, 0xCD, 0xAB, 0x05, 0x00,
    0x15, 0x00, 0xCD, 0xAB, 0x17, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x0E, 0x00, 0x00, 0x00, 0x15, 0x00, 0x15, 0x00,
    0xCD, 0xAB, 0x62, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x08, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x07, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x32, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x1B, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x04, 0x00, 0x00, 0x00, 0x17, 0x00, 0xCD, 0xAB, 0x0F, 0x00, 0x00, 0x00, 0x17, 0x00,
    0xCD, 0xAB, 0x34, 0x00, 0x00, 0x00, 0x18, 0x00, 0xCD, 0xAB, 0x2A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0xA8, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0xF4, 0x22, 0x00, 0x96, 0xB7, 0x17, 0x00,
    0x22, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0x1E, 0x8E,
    0x22, 0x00, 0xEA, 0x5A, 0x23, 0x00, 0x30, 0x51, 0x17, 0x00, 0xFC, 0x1D, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0xAD,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x03, 0x00,
    0x00, 0xB8, 0x0E, 0x00, 0x00, 0x80, 0x02, 0x00, 0x0E, 0x00, 0x02, 0x00, 0xE4, 0xFF, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x78, 0x0E, 0x00, 0x00, 0xF8, 0x0E, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0xC0,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0xAE, 0xB3, 0xAD, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x03, 0x00, 0x00, 0xC6, 0x10, 0x00, 0x00, 0x80, 0x02, 0x00, 0x10, 0x00, 0x02, 0x00,
    0x17, 0x00, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x86, 0x10, 0x00, 0x00, 0x06,
    0x11, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0xC0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8F, 0xAF, 0xF7, 0xAD, 0x01, 0x00,
    0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE4, 0x00, 0x00, 0x01, 0x00, 0x00, 0x9C, 0x1B, 0x00,
    0x00, 0x80, 0x03, 0x00, 0x1C, 0x00, 0x03, 0x00, 0x32, 0xFF, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
    0x00, 0x40, 0x00, 0x5C, 0x1B, 0x00, 0x00, 0xDC, 0x1B, 0x00, 0x00, 0x40, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x5B, 0xB0, 0x3B, 0xAE, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00, 0x80, 0x04, 0x00, 0x01, 0x00, 0x04, 0x00, 0x37, 0x01, 0x00, 0x7D,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0xD0, 0x01, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 0x40,
    0x04, 0x00, 0x00, 0xC0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE3, 0xB0, 0x8F, 0xAF, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00,
    0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x00, 0x00, 0x01, 0x00, 0x00, 0x86, 0x07, 0x00, 0x00, 0x80, 0x06, 0x00,
    0x08, 0x00, 0x06, 0x00, 0xC1, 0x01, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x46,
    0x07, 0x00, 0x00, 0xC6, 0x07, 0x00, 0x00, 0x40, 0x06, 0x00, 0x00, 0xC0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0xB1,
    0x5B, 0xB0, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x10, 0x0E, 0x00, 0x00, 0x80, 0x09, 0x00, 0x0D, 0x00, 0x09, 0x00, 0xDA, 0xFF, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0xD0, 0x0D, 0x00, 0x00, 0x50, 0x0E, 0x00, 0x00, 0x40, 0x09, 0x00, 0x00, 0xC0,
    0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6B, 0xB1, 0xE3, 0xB0, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x36, 0x19, 0x00, 0x00,
    0x00, 0x00, 0x3C, 0x14, 0x00, 0x00, 0x03, 0x00, 0x3C, 0x94, 0x19, 0x00, 0x00, 0x80, 0x06, 0x00, 0x19, 0x00, 0x06, 0x00,
    0x8B, 0x13, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x09, 0x00, 0x00, 0x00, 0x50, 0x3C, 0x44, 0x19, 0x00, 0x3C, 0xE4,
    0x19, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0xD0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF3, 0xB1, 0x27, 0xB1, 0x01, 0x00,
    0x00, 0x00, 0x0C, 0x00, 0x36, 0x19, 0x00, 0x00, 0x00, 0x00, 0x84, 0x8B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x16, 0x00,
    0x84, 0x0B, 0x03, 0x00, 0x16, 0x00, 0x02, 0x00, 0x12, 0x0B, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x09, 0x00, 0x00,
    0x00, 0x50, 0x00, 0x30, 0x16, 0x00, 0x00, 0xD0, 0x16, 0x00, 0x84, 0xBB, 0x02, 0x00, 0x84, 0x5B, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x37, 0xB2, 0x6B, 0xB1, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x7E, 0x07, 0x00, 0x00, 0x80, 0x06, 0x00, 0x07, 0x00, 0x06, 0x00, 0x2C, 0x01, 0x00, 0x7D,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x3E, 0x07, 0x00, 0x00, 0xBE, 0x07, 0x00, 0x00, 0x40,
    0x06, 0x00, 0x00, 0xC0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDF, 0xB4, 0xF3, 0xB1, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00,
    0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0x00, 0x00, 0x03, 0x00, 0x00, 0x12, 0x02, 0x00, 0x00, 0x80, 0x05, 0x00,
    0x01, 0x00, 0x05, 0x00, 0x3A, 0x01, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0xD2,
    0x01, 0x00, 0x00, 0x52, 0x02, 0x00, 0x00, 0x40, 0x05, 0x00, 0x00, 0xC0, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCB, 0xB7,
    0x37, 0xB2, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x80, 0x24, 0x00, 0x00, 0xC8, 0x12, 0x00, 0x24, 0x00, 0x13, 0x00, 0x6B, 0x18, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x24, 0x00, 0x00, 0xC0, 0x24, 0x00, 0x00, 0x88, 0x12, 0x00, 0x00, 0x08,
    0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xB8, 0xDF, 0xB4, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xC2, 0x00, 0x00, 0x03, 0x00, 0x00, 0x42, 0x07, 0x00, 0x00, 0x80, 0x0E, 0x00, 0x06, 0x00, 0x0E, 0x00,
    0x37, 0x01, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x02, 0x07, 0x00, 0x00, 0x82,
    0x07, 0x00, 0x00, 0x40, 0x0E, 0x00, 0x00, 0xC0, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0xB8, 0xCB, 0xB7, 0x00, 0x00,
    0x01, 0x00, 0x0F, 0x00, 0x78, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x80, 0x1E, 0x00,
    0x00, 0x80, 0x0E, 0x00, 0x1E, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x55, 0x55, 0xAB, 0x2A, 0x1E, 0x00, 0x55, 0xD5, 0x1E, 0x00, 0xAB, 0x2A, 0x0E, 0x00, 0x55, 0xD5, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x97, 0xB8, 0x0F, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C,
    0x00, 0x00, 0x03, 0x00, 0x00, 0xFC, 0x1D, 0x00, 0x00, 0x80, 0x13, 0x00, 0x1D, 0x00, 0x13, 0x00, 0xC6, 0xFF, 0x00, 0x7D,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0xBC, 0x1D, 0x00, 0x00, 0x3C, 0x1E, 0x00, 0x00, 0x40,
    0x13, 0x00, 0x00, 0xC0, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xBB, 0x53, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00,
    0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x03, 0x00, 0x00, 0xDA, 0x1C, 0x00, 0x00, 0x80, 0x14, 0x00,
    0x1C, 0x00, 0x14, 0x00, 0xBC, 0xFF, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x9A,
    0x1C, 0x00, 0x00, 0x1A, 0x1D, 0x00, 0x00, 0x40, 0x14, 0x00, 0x00, 0xC0, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4F, 0xBC,
    0x97, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x20, 0x00, 0x00, 0x86, 0x0D, 0x00, 0x20, 0x00, 0x0D, 0x00, 0xC4, 0x23, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x20, 0x00, 0x00, 0xC0, 0x20, 0x00, 0x00, 0x46, 0x0D, 0x00, 0x00, 0xC6,
    0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x93, 0xBC, 0x83, 0xBB, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x00, 0x00, 0x84, 0x20, 0x00, 0x00, 0x80, 0x18, 0x00, 0x20, 0x00, 0x18, 0x00,
    0xB5, 0x00, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x44, 0x20, 0x00, 0x00, 0xC4,
    0x20, 0x00, 0x00, 0x40, 0x18, 0x00, 0x00, 0xC0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0xBD, 0x4F, 0xBC, 0x01, 0x00,
    0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x01, 0x00, 0x00, 0x6C, 0x0B, 0x00,
    0x00, 0x80, 0x17, 0x00, 0x0B, 0x00, 0x17, 0x00, 0x54, 0xF5, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
    0x00, 0x40, 0x00, 0x2C, 0x0B, 0x00, 0x00, 0xAC, 0x0B, 0x00, 0x00, 0x40, 0x17, 0x00, 0x00, 0xC0, 0x17, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x5F, 0xBD, 0x93, 0xBC, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0E, 0x00, 0x00, 0xF8, 0x12, 0x00, 0x0E, 0x00, 0x12, 0x00, 0x0C, 0x01, 0x00, 0x7D,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x0E, 0x00, 0x00, 0xC0, 0x0E, 0x00, 0x00, 0xB8,
    0x12, 0x00, 0x00, 0x38, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0xBD, 0x1B, 0xBD, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00,
    0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0C, 0x00, 0x00, 0xC0, 0x18, 0x00,
    0x0C, 0x00, 0x18, 0x00, 0xF1, 0x0E, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40,
    0x0C, 0x00, 0x00, 0xC0, 0x0C, 0x00, 0x00, 0x80, 0x18, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B, 0xBE,
    0x5F, 0xBD, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x0D, 0x00, 0x00, 0x84, 0x17, 0x00, 0x0D, 0x00, 0x17, 0x00, 0x92, 0x13, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x0D, 0x00, 0x00, 0xC0, 0x0D, 0x00, 0x00, 0x44, 0x17, 0x00, 0x00, 0xC4,
    0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6F, 0xBE, 0xE7, 0xBD, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xAE, 0x19, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x98, 0x13, 0x00, 0x00, 0x80, 0x18, 0x00, 0x13, 0x00, 0x18, 0x00,
    0x2B, 0x02, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x58, 0x13, 0x00, 0x00, 0xD8,
    0x13, 0x00, 0x00, 0x40, 0x18, 0x00, 0x00, 0xC0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3, 0xBE, 0x2B, 0xBE, 0x00, 0x00,
    0x01, 0x00, 0x0F, 0x00, 0x78, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x80, 0x25, 0x00,
    0x00, 0x80, 0x1A, 0x00, 0x25, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x55, 0x55, 0xAB, 0x2A, 0x25, 0x00, 0x55, 0xD5, 0x25, 0x00, 0xAB, 0x2A, 0x1A, 0x00, 0x55, 0xD5, 0x1A, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x6F, 0xBE
};

SavedGameInDosFormat_Test::SavedGameInDosFormat_Test()
{

}

SavedGameInDosFormat_Test::~SavedGameInDosFormat_Test()
{

}

TEST(SavedGameInDosFormat_Test, LoadSavedGame)
{
    FileChunk* fileChunk = new FileChunk(3166);
    std::memcpy(fileChunk->GetChunk(), rawSavedGameData, 3166);
    SavedGameInDosFormat savedGame(fileChunk);
    EXPECT_TRUE(savedGame.Load());

    EXPECT_EQ(savedGame.GetSignature(), "C3D");
    EXPECT_TRUE(savedGame.GetPresent());
    EXPECT_EQ(savedGame.GetName(), "level3");
    EXPECT_EQ(savedGame.GetDifficulty(), 2);
    EXPECT_EQ(savedGame.GetMapOn(), 2);
    EXPECT_EQ(savedGame.GetBolts(), 5);
    EXPECT_EQ(savedGame.GetNukes(), 2);
    EXPECT_EQ(savedGame.GetPotions(), 21);
    EXPECT_EQ(savedGame.GetKeys(0), 0);
    EXPECT_EQ(savedGame.GetKeys(1), 0);
    EXPECT_EQ(savedGame.GetKeys(2), 0);
    EXPECT_EQ(savedGame.GetKeys(3), 1);
    EXPECT_EQ(savedGame.GetScrolls(0), 0);
    EXPECT_EQ(savedGame.GetScrolls(7), 0);
    EXPECT_EQ(savedGame.GetScore(), 12700);
    EXPECT_EQ(savedGame.GetBody(), 32);
    EXPECT_EQ(savedGame.GetShotpower(), 0);
    constexpr uint16_t planeSize = 40u * 28u * sizeof(uint16_t);
    EXPECT_EQ(savedGame.GetPlane0()->GetSize(), planeSize);
    EXPECT_EQ(savedGame.GetPlane2()->GetSize(), planeSize);
    EXPECT_EQ(savedGame.GetNumberOfObjects(), 24);

    const SavedGameInDosFormat::ObjectInDosFormat& firstObject = savedGame.GetObject(0);
    EXPECT_EQ(firstObject.active, 1);
    EXPECT_EQ(firstObject.obclass, 1);  // playerobj
    EXPECT_EQ(firstObject.stateOffset, 6056);
    EXPECT_EQ(firstObject.shootable , 0);
    EXPECT_EQ(firstObject.tileObject, 0);
    EXPECT_EQ(firstObject.distance, 0);
    EXPECT_EQ(firstObject.dir, 0);
    const SavedGameInDosFormat::ObjectInDosFormat& secondObject = savedGame.GetObject(1);
    EXPECT_EQ(secondObject.active, 1);
    EXPECT_EQ(secondObject.obclass, 12);  // inertobj
    EXPECT_EQ(secondObject.stateOffset, 6574);
    EXPECT_EQ(secondObject.shootable, 0);
    EXPECT_EQ(secondObject.tileObject, 0);
    EXPECT_EQ(secondObject.distance, 14336);
    EXPECT_EQ(secondObject.dir, 3);  // west
    const SavedGameInDosFormat::ObjectInDosFormat& lastObject = savedGame.GetObject(23);
    EXPECT_EQ(firstObject.active, 1);
    EXPECT_EQ(lastObject.obclass, 15);  // gateobj
    EXPECT_EQ(lastObject.stateOffset, 6264);
    EXPECT_EQ(lastObject.shootable, 0);
    EXPECT_EQ(lastObject.tileObject, 0);
    EXPECT_EQ(lastObject.distance, 0);
    EXPECT_EQ(lastObject.dir, 8); // nodir
}
