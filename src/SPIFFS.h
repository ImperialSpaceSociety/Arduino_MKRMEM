/*
  Copyright (c) 2019 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef ARDUINO_SPIFFS_H_
#define ARDUINO_SPIFFS_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "spiffs.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class SPIFFS
{
public:

  s32_t mount();

private:

  spiffs _fs;
  
  u8_t   _spiffs_work_buf[SPIFFS_CFG_LOG_PAGE_SZ(0)*2];
  u8_t   _spiffs_fds[32*4];
  u8_t   _spiffs_cache_buf[(SPIFFS_CFG_LOG_PAGE_SZ(0)+32)*4];

};

#endif /* ARDUINO_SPIFFS_H_ */
