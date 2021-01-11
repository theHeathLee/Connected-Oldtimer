/**
* @file NexObject.cpp
*
* The implementation of class NexObject. 
*
* @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
* @date    2015/8/13
* @copyright 
* Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* Port for Particle platform (particle.io)
* by BSpranger & ScruffR (Dec. 2015)
*/

#include "NexObject.h"
#include "NexHardware.h"

NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value)
{
    this->__pid = pid;
    this->__cid = cid;
    this->__name = name;
    this->__value = value;
}

void NexObject::setObjValue(uint8_t type, void *value)
{
    if (__value)
    {
        switch (type)
        {
        case NEX_EVENT_VALUE:
           *((unsigned long *)__value) = (((uint8_t *)value)[0]) | (((unsigned long)((uint8_t *)value)[1]) << 8) | (((unsigned long)((uint8_t *)value)[2]) << 16) | (((unsigned long)((uint8_t *)value)[3]) << 24);
        break;
        case NEX_EVENT_STRING:
        //while (*((unsigned char *)(value+i)) != 0)
        //{
        //#if defined(SPARK)
        //Particle.process();
        //#endif
        // *((unsigned char *)(__value+i)) = *((unsigned char *)(value+i));
        //  i++;
        //}        
        break;
        default:
        //*(__value) = 0;
        break;
        }
    }
}

uint8_t NexObject::getObjPid(void)
{
    return __pid;
}

uint8_t NexObject::getObjCid(void)
{
    return __cid;
}

const char* NexObject::getObjName(void)
{
    return __name;
}

void * NexObject::getObjValue(void)
{
    return __value;
}

void NexObject::printObjInfo(void)
{
    dbSerialPrint("[");
    dbSerialPrint((uint32_t)this);
    dbSerialPrint(":");
    dbSerialPrint(__pid);
    dbSerialPrint(",");
    dbSerialPrint(__cid);
    dbSerialPrint(",");
    if (__name)
    {
        dbSerialPrint(__name);
    }
    else
    {
        dbSerialPrint("(null)");
    }
    dbSerialPrint(",");
    if (__value)
    {
        dbSerialPrint((uint32_t)__value);
    }
    else
    {
        dbSerialPrint("(null)");
    }        
    dbSerialPrintln("]");
}

bool NexObject::getValue(const char* valueType, uint32_t* value)
{
  return NexGetValue(getObjName(), valueType, value);
}

bool NexObject::setValue(const char* valueType, uint32_t value)
{
  return NexSetValue(getObjName(), valueType, value);
}

uint16_t NexObject::getString(const char* valueType, char* text, uint16_t len)
{
  return NexGetString(getObjName(), valueType, text, len);
}

bool NexObject::setString(const char* valueType, const char* text)
{
  return NexSetString(getObjName(), valueType, text);
}
