//  ***************************************************************************
/// @file    src.c
/// @author  NeoProg
//  ***************************************************************************
#include <sam.h>
#include "scr.h"
#include "movement_driver.h"
#include "limbs_driver.h"
#include "veeprom.h"
#include "multimedia.h"

#define SCR_CMD_CALCULATE_CHECKSUM				(0x01)

#define SCR_CMD_SELECT_GAIT_UP					(0x02)
#define SCR_CMD_SELECT_GAIT_BASE				(0x03)
#define SCR_CMD_SELECT_GAIT_DOWN				(0x04)
#define SCR_CMD_SELECT_GAIT_DIRECT_MOVEMENT		(0x05)
#define SCR_CMD_SELECT_GAIT_REVERSE_MOVEMENT	(0x06)
#define SCR_CMD_SELECT_GAIT_ROTATE_LEFT			(0x07)
#define SCR_CMD_SELECT_GAIT_ROTATE_RIGHT		(0x08)

#define SCR_CMD_RESET							(0xAA)


uint8_t scr = 0;
int16_t x = 0;
int16_t y = 0;
int16_t z = 0;

point_3d_t point_list_1[6] = { { LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE},
							   { LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}};
point_3d_t point_list_2[6] = { { LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE},
							   {          150,            0,          150}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}, {LIMB_NO_MOVE, LIMB_NO_MOVE, LIMB_NO_MOVE}};

//  ***************************************************************************
/// @brief	Special command register process
/// @return	none
//  ***************************************************************************

void test() {
	
	point_list_1[0].x = 120;
	point_list_1[0].y = -85;
	point_list_1[0].z = 20;
	
	point_list_1[1].x = 120;
	point_list_1[1].y = -85;
	point_list_1[1].z = 50;
	
	point_list_1[2].x = 120;
	point_list_1[2].y = -85;
	point_list_1[2].z = -120;
	
	point_list_1[3].x = 120;
	point_list_1[3].y = -85;
	point_list_1[3].z = 120;
	
	point_list_1[4].x = 120;
	point_list_1[4].y = -85;
	point_list_1[4].z = -50;
	
	point_list_1[5].x = 120;
	point_list_1[5].y = -85;
	point_list_1[5].z = -20;
	limbs_driver_start_move(point_list_1);
	
	while (limbs_driver_is_move_complete() == false) {
		servo_driver_process();
		limbs_driver_process();
	}
	
	
	point_list_1[0].x = 150;
	point_list_1[0].y = -30;
	point_list_1[0].z = 70;
	
	point_list_1[1].x = 120;
	point_list_1[1].y = -85;
	point_list_1[1].z = 0;
	
	point_list_1[2].x = 150;
	point_list_1[2].y = -30;
	point_list_1[2].z = -70;
	
	point_list_1[3].x = 120;
	point_list_1[3].y = -85;
	point_list_1[3].z = 70;
	
	point_list_1[4].x = 150;
	point_list_1[4].y = -30;
	point_list_1[4].z = 0;
	
	point_list_1[5].x = 120;
	point_list_1[5].y = -85;
	point_list_1[5].z = -70;
	limbs_driver_start_move(point_list_1);
	
	while (limbs_driver_is_move_complete() == false) {
		servo_driver_process();
		limbs_driver_process();
	}
	
	
	point_list_1[0].x = 120;
	point_list_1[0].y = -85;
	point_list_1[0].z = 120;
	
	point_list_1[1].x = 120;
	point_list_1[1].y = -85;
	point_list_1[1].z = -50;
	
	point_list_1[2].x = 120;
	point_list_1[2].y = -85;
	point_list_1[2].z = -20;
	
	point_list_1[3].x = 120;
	point_list_1[3].y = -85;
	point_list_1[3].z = 20;
	
	point_list_1[4].x = 120;
	point_list_1[4].y = -85;
	point_list_1[4].z = 50;
	
	point_list_1[5].x = 120;
	point_list_1[5].y = -85;
	point_list_1[5].z = -120;
	limbs_driver_start_move(point_list_1);
	
	while (limbs_driver_is_move_complete() == false) {
		servo_driver_process();
		limbs_driver_process();
	}
	
	
	point_list_1[0].x = 120;
	point_list_1[0].y = -85;
	point_list_1[0].z = 70;
	
	point_list_1[1].x = 150;
	point_list_1[1].y = -30;
	point_list_1[1].z = 0;
	
	point_list_1[2].x = 120;
	point_list_1[2].y = -85;
	point_list_1[2].z = -70;
	
	point_list_1[3].x = 150;
	point_list_1[3].y = -30;
	point_list_1[3].z = 70;
	
	point_list_1[4].x = 120;
	point_list_1[4].y = -85;
	point_list_1[4].z = 0;
	
	point_list_1[5].x = 150;
	point_list_1[5].y = -30;
	point_list_1[5].z = -70;
	limbs_driver_start_move(point_list_1);
	
	while (limbs_driver_is_move_complete() == false) {
		servo_driver_process();
		limbs_driver_process();
	}
}


void scr_process(void) {
	
	switch (scr) {
		
		case 0x01:
			point_list_1[0].x = +85;
			point_list_1[0].y = -85;
			point_list_1[0].z = +85;
			
			point_list_1[1].x = +125;
			point_list_1[1].y = -85;
			point_list_1[1].z = 0;
			
			point_list_1[2].x = +85;
			point_list_1[2].y = -85;
			point_list_1[2].z = -85;
		
			point_list_1[3].x = +85;
			point_list_1[3].y = -85;
			point_list_1[3].z = +85;
			
			point_list_1[4].x = +125;
			point_list_1[4].y = -85;
			point_list_1[4].z = 0;
			
			point_list_1[5].x = +85;
			point_list_1[5].y = -85;
			point_list_1[5].z = -85;
			limbs_driver_start_move(point_list_1);
			break;
		
		case 0x02:
			for (uint32_t i = 0; i < 5; ++i) {
				test();
			}
			
			point_list_1[0].x = +85;
			point_list_1[0].y = -85;
			point_list_1[0].z = +85;
			
			point_list_1[1].x = +125;
			point_list_1[1].y = -85;
			point_list_1[1].z = 0;
			
			point_list_1[2].x = +85;
			point_list_1[2].y = -85;
			point_list_1[2].z = -85;
		
			point_list_1[3].x = +85;
			point_list_1[3].y = -85;
			point_list_1[3].z = +85;
			
			point_list_1[4].x = +125;
			point_list_1[4].y = -85;
			point_list_1[4].z = 0;
			
			point_list_1[5].x = +85;
			point_list_1[5].y = -85;
			point_list_1[5].z = -85;
			limbs_driver_start_move(point_list_1);
			break;
			
		/*case 0x02:
			point_list_1[3].x = +85;
			point_list_1[3].y = -85;
			point_list_1[3].z = +135;
			point_list_1[5].x = +85;
			point_list_1[5].y = -85;
			point_list_1[5].z = -50;
			limbs_driver_start_move(point_list_1);
			break;
			
		case 0x03:
			point_list_1[3].x = +85;
			point_list_1[3].y = -85;
			point_list_1[3].z = +50;
			point_list_1[5].x = +85;
			point_list_1[5].y = -85;
			point_list_1[5].z = -135;
			limbs_driver_start_move(point_list_1);
			break;*/
			
		case 0x03:
			point_list_1[0].x = 120;
			point_list_1[0].y = -85;
			point_list_1[0].z = 20;
			
			point_list_1[1].x = 120;
			point_list_1[1].y = -85;
			point_list_1[1].z = 50;
			
			point_list_1[2].x = 120;
			point_list_1[2].y = -85;
			point_list_1[2].z = -120;
		
			point_list_1[3].x = 120;
			point_list_1[3].y = -85;
			point_list_1[3].z = 120;
			
			point_list_1[4].x = 120;
			point_list_1[4].y = -85;
			point_list_1[4].z = -50;
			
			point_list_1[5].x = 120;
			point_list_1[5].y = -85;
			point_list_1[5].z = -20;
			limbs_driver_start_move(point_list_1);
			break;
			
		case 0x04:
			point_list_1[0].x = 150;
			point_list_1[0].y = -30;
			point_list_1[0].z = 70;
			
			point_list_1[1].x = 120;
			point_list_1[1].y = -85;
			point_list_1[1].z = 0;
			
			point_list_1[2].x = 150;
			point_list_1[2].y = -30;
			point_list_1[2].z = -70;
		
			point_list_1[3].x = 120;
			point_list_1[3].y = -85;
			point_list_1[3].z = 70;
			
			point_list_1[4].x = 150;
			point_list_1[4].y = -30;
			point_list_1[4].z = 0;
			
			point_list_1[5].x = 120;
			point_list_1[5].y = -85;
			point_list_1[5].z = -70;
			limbs_driver_start_move(point_list_1);
			break;
			
		case 0x05:
			point_list_1[0].x = 120;
			point_list_1[0].y = -85;
			point_list_1[0].z = 120;
			
			point_list_1[1].x = 120;
			point_list_1[1].y = -85;
			point_list_1[1].z = -50;
			
			point_list_1[2].x = 120;
			point_list_1[2].y = -85;
			point_list_1[2].z = -20;
		
			point_list_1[3].x = 120;
			point_list_1[3].y = -85;
			point_list_1[3].z = 20;
			
			point_list_1[4].x = 120;
			point_list_1[4].y = -85;
			point_list_1[4].z = 50;
			
			point_list_1[5].x = 120;
			point_list_1[5].y = -85;
			point_list_1[5].z = -120;
			limbs_driver_start_move(point_list_1);
			break;
		
		case 0x06:
			point_list_1[0].x = 120;
			point_list_1[0].y = -85;
			point_list_1[0].z = 70;
			
			point_list_1[1].x = 150;
			point_list_1[1].y = -30;
			point_list_1[1].z = 0;
			
			point_list_1[2].x = 120;
			point_list_1[2].y = -85;
			point_list_1[2].z = -70;
		
			point_list_1[3].x = 150;
			point_list_1[3].y = -30;
			point_list_1[3].z = 70;
			
			point_list_1[4].x = 120;
			point_list_1[4].y = -85;
			point_list_1[4].z = 0;
			
			point_list_1[5].x = 150;
			point_list_1[5].y = -30;
			point_list_1[5].z = -70;
			limbs_driver_start_move(point_list_1);
			break;
			
		case 0x10:
			point_list_1[0].x = x;
			point_list_1[0].y = y;
			point_list_1[0].z = z;
			limbs_driver_start_move(point_list_1);
			break;
			
		case 0x11:
			limbs_driver_set_movement_iteration_count(x);
			break;
			
		/*case SCR_CMD_CALCULATE_CHECKSUM:
			veeprom_update_checksum();
			break;
			
		case SCR_CMD_SELECT_GAIT_UP:
			movement_driver_select_sequence(SEQUENCE_UP);
			break;
		
		case SCR_CMD_SELECT_GAIT_BASE:
			movement_driver_select_sequence(SEQUENCE_BASE);
			break;	
	
		case SCR_CMD_SELECT_GAIT_DOWN:
			movement_driver_select_sequence(SEQUENCE_DOWN);
			break;
			
		case SCR_CMD_SELECT_GAIT_DIRECT_MOVEMENT:
			movement_driver_select_sequence(SEQUENCE_DIRECT_MOVEMENT);
			break;
			
		case SCR_CMD_SELECT_GAIT_REVERSE_MOVEMENT:
			movement_driver_select_sequence(SEQUENCE_REVERSE_MOVEMENT);
			break;
		
		case SCR_CMD_SELECT_GAIT_ROTATE_LEFT:
			movement_driver_select_sequence(SEQUENCE_ROTATE_LEFT);
			break;
			
		case SCR_CMD_SELECT_GAIT_ROTATE_RIGHT:
			movement_driver_select_sequence(SEQUENCE_ROTATE_RIGHT);
			break;*/
			
		case SCR_CMD_RESET:
			REG_RSTC_CR = 0xA5000005;
			break;
	}
	
	scr = 0x00;
}