//  ***************************************************************************
/// @file    src.c
/// @author  NeoProg
//  ***************************************************************************
#include "scr.h"

#include <sam.h>
#include "movement_engine.h"
#include "limbs_driver.h"
#include "servo_driver.h"
#include "veeprom.h"
#include "gui.h"
#include "led.h"
#include "monitoring.h"

#define SCR_CMD_SELECT_SEQUENCE_UP                      (0x01)
#define SCR_CMD_SELECT_SEQUENCE_DOWN                    (0x02)
#define SCR_CMD_SELECT_SEQUENCE_DIRECT_MOVEMENT         (0x03)
#define SCR_CMD_SELECT_SEQUENCE_REVERSE_MOVEMENT        (0x04)
#define SCR_CMD_SELECT_SEQUENCE_ROTATE_LEFT             (0x05)
#define SCR_CMD_SELECT_SEQUENCE_ROTATE_RIGHT            (0x06)
#define SCR_CMD_SELECT_SEQUENCE_DIRECT_MOVEMENT_SHORT   (0x07)
#define SCR_CMD_SELECT_SEQUENCE_REVERSE_MOVEMENT_SHORT  (0x08)
#define SCR_CMD_SELECT_SEQUENCE_ROTATE_LEFT_SHORT       (0x09)
#define SCR_CMD_SELECT_SEQUENCE_ROTATE_RIGHT_SHORT      (0x0A)

#define SCR_CMD_SELECT_SEQUENCE_ATTACK_LEFT             (0x10)
#define SCR_CMD_SELECT_SEQUENCE_ATTACK_RIGHT            (0x11)
#define SCR_CMD_SELECT_SEQUENCE_DANCE                   (0x20)

#define SCR_CMD_SELECT_SEQUENCE_INCREASE_HEIGHT         (0x88)
#define SCR_CMD_SELECT_SEQUENCE_DECREASE_HEIGHT         (0x89)
#define SCR_CMD_SELECT_SEQUENCE_NONE                    (0x90)

#define SCR_CMD_CALCULATE_CHECKSUM                      (0xFD)
#define SCR_CMD_RESET                                   (0xFE)


uint8_t scr = 0;
int32_t scr_argument = 0;


//  ***************************************************************************
/// @brief    Special command register process
/// @return    none
//  ***************************************************************************
void scr_process(void) {
    
    switch (scr) {
        
        case SCR_CMD_SELECT_SEQUENCE_UP:
            movement_engine_select_sequence(SEQUENCE_UP);
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_DOWN:
            movement_engine_select_sequence(SEQUENCE_DOWN);
            break;
            
            
        case SCR_CMD_SELECT_SEQUENCE_DIRECT_MOVEMENT:
            movement_engine_select_sequence(SEQUENCE_DIRECT_MOVEMENT);
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_REVERSE_MOVEMENT:
            movement_engine_select_sequence(SEQUENCE_REVERSE_MOVEMENT);
            break;
        
        case SCR_CMD_SELECT_SEQUENCE_ROTATE_LEFT:
            movement_engine_select_sequence(SEQUENCE_ROTATE_LEFT);
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_ROTATE_RIGHT:
            movement_engine_select_sequence(SEQUENCE_ROTATE_RIGHT);
            break;
            
            
        case SCR_CMD_SELECT_SEQUENCE_DIRECT_MOVEMENT_SHORT:
            movement_engine_select_sequence(SEQUENCE_DIRECT_MOVEMENT_SHORT);
            break;
        
        case SCR_CMD_SELECT_SEQUENCE_REVERSE_MOVEMENT_SHORT:
            movement_engine_select_sequence(SEQUENCE_REVERSE_MOVEMENT_SHORT);
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_ROTATE_LEFT_SHORT:
            movement_engine_select_sequence(SEQUENCE_ROTATE_LEFT_SHORT);
            break;
        
        case SCR_CMD_SELECT_SEQUENCE_ROTATE_RIGHT_SHORT:
            movement_engine_select_sequence(SEQUENCE_ROTATE_RIGHT_SHORT);
            break;
            
            
        case SCR_CMD_SELECT_SEQUENCE_ATTACK_LEFT:
            movement_engine_select_sequence(SEQUENCE_ATTACK_LEFT);
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_ATTACK_RIGHT:
            movement_engine_select_sequence(SEQUENCE_ATTACK_RIGHT);
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_DANCE:
            movement_engine_select_sequence(SEQUENCE_DANCE);
            break;
                
        case SCR_CMD_SELECT_SEQUENCE_INCREASE_HEIGHT:
            movement_engine_increase_height();
            break;
            
        case SCR_CMD_SELECT_SEQUENCE_DECREASE_HEIGHT:
            movement_engine_decrease_height();
            break;

        case SCR_CMD_SELECT_SEQUENCE_NONE:
            movement_engine_select_sequence(SEQUENCE_NONE);
            break;
        
        /*case SCR_CMD_CALCULATE_CHECKSUM:
            veeprom_update_checksum();
            break;*/
            
        case SCR_CMD_RESET:
            REG_RSTC_CR = 0xA5000005;
            break;
    }
    
    scr = 0x00;
}