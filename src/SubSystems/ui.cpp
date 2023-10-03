#include "ARMS/chassis.h"
#include "gif-pros/gifclass.hpp"
#include <sstream>
#include <iostream>
#include <map>
namespace selector{

	int auton;
	int autonCount;
	const char *btnmMap[] = {"","","","","","","","","","",""};

	lv_obj_t *tabview;
	lv_obj_t *redBtnm;
	lv_obj_t *blueBtnm;
	lv_obj_t *debug;
	lv_obj_t *motors;
	lv_obj_t *runningauto;
	lv_obj_t *debugAuto;
	lv_obj_t *debuglabel;
	lv_obj_t *debuginactivelabel;
	lv_obj_t *cb;
	lv_obj_t *drivemotorlabel;
	lv_obj_t *othermotorlabel;

	lv_res_t cb_release_action(lv_obj_t * cb)
	{
		/*A check box is clicked*/
		//printf("%s state: %d\n", lv_cb_get_text(cb), lv_cb_is_checked(cb));

		if (lv_cb_is_checked(cb) == 1) {
			lv_label_set_text(debugAuto, "Auton Debug: True");
			lv_obj_align(debugAuto, NULL, LV_ALIGN_CENTER, 0, 75);
		}

		else if (lv_cb_is_checked(cb) == 0) {
			lv_label_set_text(debugAuto, "Auton Debug: False");
			lv_obj_align(debugAuto, NULL, LV_ALIGN_CENTER, 0, 75);
		}


		return LV_RES_OK;
	}

	lv_res_t debugChecker(lv_obj_t *obj) {
		return LV_RES_OK;
	}

	lv_res_t redBtnmAction(lv_obj_t *btnm, const char *txt){
		//printf("red button: %s released\n", txt);

		for(int i = 0; i < autonCount; i++){
			if(strcmp(txt, btnmMap[i]) == 0){
				auton = i+1;
			}
		}

		std::stringstream ss;

		ss << "Auton Selected: Red " << txt;

		auto temp = ss.str();

		auto text = temp.c_str();

		lv_label_set_text(runningauto, text);
		lv_obj_align(runningauto, NULL, LV_ALIGN_CENTER, 0, 100);

		printf("%i\n", auton);

		return LV_RES_OK; 
	}


	lv_res_t blueBtnmAction(lv_obj_t *btnm, const char *txt){
		//printf("blue button: %s released\n", txt);

		for(int i = 0; i < autonCount; i++){
			if(strcmp(txt, btnmMap[i]) == 0){
				auton = -(i+1);
			}
		}

		std::stringstream ss;

		ss << "Auton Selected: Blue " << txt;

		auto temp = ss.str();

		auto text = temp.c_str();

		lv_label_set_text(runningauto, text);
		lv_obj_align(runningauto, NULL, LV_ALIGN_CENTER, 0, 100);

		printf("%i\n", auton);

		return LV_RES_OK; // return OK because the button matrix is not deleted
	}

	lv_res_t skillsBtnAction(lv_obj_t *btn){
		//printf("skills pressed");
		auton = 0;

		lv_label_set_text(runningauto, "Auton Selected: Skills");
		lv_obj_align(runningauto, NULL, LV_ALIGN_CENTER, 0, 100);

		printf("%i\n", auton);

		return LV_RES_OK;
	}

	void othertempinfo() {
		double IntakeT = Intake.get_temperature();
		double cata = Catapult.get_temperature();

		std::stringstream ss;

		ss << "Intake Temp: " << IntakeT << "\nCatapult: " << cata;

		auto temp = ss.str();

		auto othertemptext = temp.c_str();
		
		lv_label_set_text(othermotorlabel, othertemptext);
		lv_obj_align(othermotorlabel, NULL, LV_ALIGN_IN_TOP_RIGHT, -50, 0);
	}

	void drivetempinfo() {
		double LFT = (*arms::chassis::leftMotors)[0].get_temperature();
		double LBT = (*arms::chassis::leftMotors)[1].get_temperature();
		double RFT = (*arms::chassis::rightMotors)[0].get_temperature();
		double RBT = (*arms::chassis::rightMotors)[1].get_temperature();
		

		std::stringstream ss;

		ss << "Left Front Temp: " << LFT << "\nLeft Back Temp: " << LBT << "\nRight Front Temp: " << RFT << "\nRight Back Temp: " << RBT;
 
		auto temp = ss.str();

		auto drivetemptext = temp.c_str();
		
		lv_label_set_text(drivemotorlabel, drivetemptext);
		lv_obj_align(drivemotorlabel, NULL, LV_ALIGN_IN_TOP_LEFT, 10, -10);
	}

	int tabWatcher() {
		int activeTab = lv_tabview_get_tab_act(tabview);
		while(1){
			drivetempinfo();
			othertempinfo();
			int currentTab = lv_tabview_get_tab_act(tabview);
			if(currentTab != activeTab){
				activeTab = currentTab;
				if(activeTab == 0){
					if(auton == 0) auton = 1;
					auton = abs(auton);
					lv_btnm_set_toggle(redBtnm, true, abs(auton)-1);
				}else if(activeTab == 1){
					if(auton == 0) auton = -1;
					auton = -abs(auton);
					lv_btnm_set_toggle(blueBtnm, true, abs(auton)-1);
				}else{
					auton = 0;
				}
			}
			

			pros::delay(20);
		}
	}

	void runauton() {


		if (auton == 0)
			autons::autonskills();

		else if (auton == 1)
			autons::redLeftStart();
		
		else if (auton == 2)
			autons::redRightStart();

		else if (auton == -1)
			autons::blueLeftStart();

		else if (auton == -2)
			autons::blueRightStart();
	}

	void shutdown() {
		lv_tabview_clean(tabview);
		lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
		lv_obj_set_size(obj, 480, 240);
		lv_obj_set_style(obj, &lv_style_transp);
		lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);
		static Gif gif("/usd/giphy.gif", obj);
	}

	void debugRuns() {
		if (lv_cb_is_checked(cb) == 1 &&  controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
			shutdown();
			
			runauton();
		}
	}
 
	void init(int default_auton, const char **autons){

		// lvgl theme
		lv_theme_t *rth = lv_theme_alien_init(360, NULL);
		lv_theme_set_current(rth);

		int i = 0;
		do{
			memcpy(&btnmMap[i], &autons[i], sizeof(&autons));
			i++;
		}while(strcmp(autons[i], "") != 0);

		autonCount = i;
		auton = default_auton;

		// create a tab view object
		tabview = lv_tabview_create(lv_scr_act(), NULL);

		// add 3 tabs (the tabs are page (lv_page) and can be scrolled
		lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
		lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
		lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");
		lv_obj_t *debugTab = lv_tabview_add_tab(tabview, "Debugging");
		lv_obj_t *motorsTab = lv_tabview_add_tab(tabview, "Motor Info");

		//set default tab
		if(auton < 0){
			lv_tabview_set_tab_act(tabview, 1, LV_ANIM_NONE);
		}else if(auton == 0){
			lv_tabview_set_tab_act(tabview, 2, LV_ANIM_NONE);
		}

		// add content to the tabs
		//Debugging
		lv_style_t style_border;
		lv_style_copy(&style_border, &lv_style_pretty_color);
		style_border.glass = 1;
		style_border.body.empty = 1;
		lv_obj_t * cont;
		cont = lv_cont_create(debugTab, NULL);
		lv_cont_set_layout(cont, LV_LAYOUT_COL_L);  
		lv_cont_set_fit(cont, true, true);      
		lv_obj_set_style(cont, &style_border);
		cb = lv_cb_create(cont, NULL);
		lv_cb_set_text(cb, "Run Debug");
		lv_cb_set_action(cb, cb_release_action);
		lv_obj_align(cont, NULL, LV_ALIGN_CENTER, 0, 0);


		debugAuto = lv_label_create(tabview, NULL);
		lv_label_set_text(debugAuto, "Auton Debug: False");
		lv_obj_set_size(debugAuto, 450, 50);
		lv_obj_set_pos(debugAuto, 0, 140);
		lv_obj_align(debugAuto, NULL, LV_ALIGN_CENTER, 0, 75);
		
		runningauto = lv_label_create(tabview, NULL);
		lv_label_set_text(runningauto, "Default Auton Selected: Skills");
		lv_obj_set_size(runningauto, 450, 50);
		lv_obj_set_pos(runningauto, 0, 200);
		lv_obj_align(runningauto, NULL, LV_ALIGN_CENTER, 0, 100);





		//motor info
		drivemotorlabel = lv_label_create(motorsTab, NULL);
		othermotorlabel = lv_label_create(motorsTab, NULL);

		drivetempinfo();
		othertempinfo();



		
		// button matrix
		redBtnm = lv_btnm_create(redTab, NULL);
		lv_btnm_set_map(redBtnm, btnmMap);
		lv_btnm_set_action(redBtnm, redBtnmAction);
		lv_btnm_set_toggle(redBtnm, true, abs(auton)-1);//3
		lv_obj_set_size(redBtnm, 450, 50);
		lv_obj_set_pos(redBtnm, 0, 100);
		lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);


		// blue tab
		blueBtnm = lv_btnm_create(blueTab, NULL);
		lv_btnm_set_map(blueBtnm, btnmMap);
		lv_btnm_set_action(blueBtnm, *blueBtnmAction);
		lv_btnm_set_toggle(blueBtnm, true, abs(auton)-1);
		lv_obj_set_size(blueBtnm, 450, 50);
		lv_obj_set_pos(blueBtnm, 0, 150);
		lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

		// skills tab
		lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
		lv_obj_t *label = lv_label_create(skillsBtn, NULL);
		lv_label_set_text(label, "Skills");
		lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, *skillsBtnAction);
		lv_obj_set_size(skillsBtn, 450, 50);
		lv_obj_set_pos(skillsBtn, 0, 100);
		lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);
		// start tab watcher
		pros::Task tabWatcher_task(tabWatcher);

	}

} // namespace selector