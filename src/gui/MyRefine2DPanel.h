#ifndef __MyRefine2DPanel__
#define __MyRefine2DPanel__

/**
@file
Subclass of Refine3DPanel, which is generated by wxFormBuilder.
*/

#include "ProjectX_gui.h"


class MyRefine2DPanel;

class ClassificationManager
{
public:
	bool start_with_random;
	MyRefine2DPanel *my_parent;

	long current_job_starttime;
	long time_of_last_update;
	int number_of_generated_3ds;

	int running_job_type;
	int number_of_rounds_to_run;
	int number_of_rounds_run;
	long current_job_id;

	long first_round_id;

	long current_refinement_package_asset_id;
	long current_input_classification_id;
	long current_output_classification_id;

	long number_of_received_particle_results;

	RefinementPackage *active_refinement_package;
	Classification *input_classification;
	Classification *output_classification;

	RunProfile active_run_profile;

	int active_number_of_classes;
	float active_low_resolution_limit;
	float active_start_high_resolution_limit;
	float active_finish_high_resolution_limit;
	float active_percent_used;
	float active_mask_radius;
	float active_angular_search_step;
	float active_search_range_x;
	float active_search_range_y;
	float active_smoothing_factor;
	bool active_exclude_blank_edges;
	bool active_auto_percent_used;

	float min_percent_used;

	void SetParent(MyRefine2DPanel *wanted_parent);

	void BeginRefinementCycle();
	void CycleRefinement();

	void RunRefinementJob();
	void SetupMerge2dJob();

	void RunInitialStartJob();

	void RunMerge2dJob();

	void ProcessJobResult(JobResult *result_to_process);
	void ProcessAllJobsFinished();

	void RemoveFilesFromScratch();


};


class MyRefine2DPanel : public Refine2DPanel
{

protected:

	void OnExpertOptionsToggle( wxCommandEvent& event );
	void OnUpdateUI( wxUpdateUIEvent& event );
	void OnInfoURL( wxTextUrlEvent& event );

	ClassificationManager my_classification_manager;


public:

	long time_of_last_result_update;
	bool refinement_package_combo_is_dirty;
	bool run_profiles_are_dirty;
	bool input_params_combo_is_dirty;
	long my_job_id;
	bool running_job;

	long selected_refinement_package;

	void Reset();

	MyRefine2DPanel( wxWindow* parent );

	void WriteInfoText(wxString text_to_write);
	void WriteErrorText(wxString text_to_write);
	void WriteBlueText(wxString text_to_write);

	void FillRefinementPackagesComboBox();
	void FillInputParamsComboBox();
	void NewRefinementPackageSelected();
	void NewInputParametersSelected();
	void FillRunProfileComboBoxes();

	void ResetAllDefaultsClick( wxCommandEvent& event );
	void StartClassificationClick( wxCommandEvent& event );

	void OnJobSocketEvent(wxSocketEvent& event);
	void TerminateButtonClick( wxCommandEvent& event );
	void FinishButtonClick( wxCommandEvent& event );
	void OnRefinementPackageComboBox( wxCommandEvent& event );
	void OnInputParametersComboBox( wxCommandEvent& event );

	void SetDefaults();
	void SetInfo();

	JobPackage my_job_package;
	JobTracker my_job_tracker;


	int length_of_process_number;





	friend class ClassificationManager;
};


#endif // __MyRefine2DPanel__