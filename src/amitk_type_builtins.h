


#ifndef __AMITK_TYPE_BUILTINS_H__
#define __AMITK_TYPE_BUILTINS_H__

#include <glib-object.h>

G_BEGIN_DECLS
/* enumerations from "amitk_canvas.h" */
GType amitk_canvas_type_get_type (void);
#define AMITK_TYPE_CANVAS_TYPE (amitk_canvas_type_get_type())
GType amitk_canvas_target_action_get_type (void);
#define AMITK_TYPE_CANVAS_TARGET_ACTION (amitk_canvas_target_action_get_type())
/* enumerations from "amitk_color_table.h" */
GType amitk_color_table_get_type (void);
#define AMITK_TYPE_COLOR_TABLE (amitk_color_table_get_type())
/* enumerations from "amitk_common.h" */
GType amitk_layout_get_type (void);
#define AMITK_TYPE_LAYOUT (amitk_layout_get_type())
GType amitk_panel_layout_get_type (void);
#define AMITK_TYPE_PANEL_LAYOUT (amitk_panel_layout_get_type())
GType amitk_view_mode_get_type (void);
#define AMITK_TYPE_VIEW_MODE (amitk_view_mode_get_type())
GType amitk_modality_get_type (void);
#define AMITK_TYPE_MODALITY (amitk_modality_get_type())
GType amitk_limit_get_type (void);
#define AMITK_TYPE_LIMIT (amitk_limit_get_type())
GType amitk_window_get_type (void);
#define AMITK_TYPE_WINDOW (amitk_window_get_type())
GType amitk_threshold_style_get_type (void);
#define AMITK_TYPE_THRESHOLD_STYLE (amitk_threshold_style_get_type())
GType amitk_help_info_get_type (void);
#define AMITK_TYPE_HELP_INFO (amitk_help_info_get_type())
/* enumerations from "amitk_data_set.h" */
GType amitk_operation_unary_get_type (void);
#define AMITK_TYPE_OPERATION_UNARY (amitk_operation_unary_get_type())
GType amitk_operation_binary_get_type (void);
#define AMITK_TYPE_OPERATION_BINARY (amitk_operation_binary_get_type())
GType amitk_interpolation_get_type (void);
#define AMITK_TYPE_INTERPOLATION (amitk_interpolation_get_type())
GType amitk_rendering_get_type (void);
#define AMITK_TYPE_RENDERING (amitk_rendering_get_type())
GType amitk_thresholding_get_type (void);
#define AMITK_TYPE_THRESHOLDING (amitk_thresholding_get_type())
GType amitk_scaling_type_get_type (void);
#define AMITK_TYPE_SCALING_TYPE (amitk_scaling_type_get_type())
GType amitk_conversion_get_type (void);
#define AMITK_TYPE_CONVERSION (amitk_conversion_get_type())
GType amitk_weight_unit_get_type (void);
#define AMITK_TYPE_WEIGHT_UNIT (amitk_weight_unit_get_type())
GType amitk_dose_unit_get_type (void);
#define AMITK_TYPE_DOSE_UNIT (amitk_dose_unit_get_type())
GType amitk_cylinder_unit_get_type (void);
#define AMITK_TYPE_CYLINDER_UNIT (amitk_cylinder_unit_get_type())
GType amitk_subject_orientation_get_type (void);
#define AMITK_TYPE_SUBJECT_ORIENTATION (amitk_subject_orientation_get_type())
GType amitk_subject_sex_get_type (void);
#define AMITK_TYPE_SUBJECT_SEX (amitk_subject_sex_get_type())
/* enumerations from "amitk_filter.h" */
GType amitk_filter_get_type (void);
#define AMITK_TYPE_FILTER (amitk_filter_get_type())
/* enumerations from "amitk_object.h" */
GType amitk_object_type_get_type (void);
#define AMITK_TYPE_OBJECT_TYPE (amitk_object_type_get_type())
GType amitk_selection_get_type (void);
#define AMITK_TYPE_SELECTION (amitk_selection_get_type())
/* enumerations from "amitk_point.h" */
GType amitk_view_get_type (void);
#define AMITK_TYPE_VIEW (amitk_view_get_type())
GType amitk_axis_get_type (void);
#define AMITK_TYPE_AXIS (amitk_axis_get_type())
GType amitk_dim_get_type (void);
#define AMITK_TYPE_DIM (amitk_dim_get_type())
GType amitk_length_unit_get_type (void);
#define AMITK_TYPE_LENGTH_UNIT (amitk_length_unit_get_type())
/* enumerations from "amitk_preferences.h" */
GType amitk_which_default_directory_get_type (void);
#define AMITK_TYPE_WHICH_DEFAULT_DIRECTORY (amitk_which_default_directory_get_type())
/* enumerations from "amitk_raw_data.h" */
GType amitk_format_get_type (void);
#define AMITK_TYPE_FORMAT (amitk_format_get_type())
GType amitk_raw_format_get_type (void);
#define AMITK_TYPE_RAW_FORMAT (amitk_raw_format_get_type())
/* enumerations from "amitk_roi.h" */
GType amitk_roi_type_get_type (void);
#define AMITK_TYPE_ROI_TYPE (amitk_roi_type_get_type())
GType amitk_roi_isocontour_range_get_type (void);
#define AMITK_TYPE_ROI_ISOCONTOUR_RANGE (amitk_roi_isocontour_range_get_type())
/* enumerations from "amitk_study.h" */
GType amitk_fuse_type_get_type (void);
#define AMITK_TYPE_FUSE_TYPE (amitk_fuse_type_get_type())
/* enumerations from "amitk_threshold.h" */
GType amitk_threshold_scale_get_type (void);
#define AMITK_TYPE_THRESHOLD_SCALE (amitk_threshold_scale_get_type())
GType amitk_threshold_arrow_get_type (void);
#define AMITK_TYPE_THRESHOLD_ARROW (amitk_threshold_arrow_get_type())
GType amitk_threshold_entry_get_type (void);
#define AMITK_TYPE_THRESHOLD_ENTRY (amitk_threshold_entry_get_type())
GType amitk_threshold_line_get_type (void);
#define AMITK_TYPE_THRESHOLD_LINE (amitk_threshold_line_get_type())
GType amitk_threshold_layout_get_type (void);
#define AMITK_TYPE_THRESHOLD_LAYOUT (amitk_threshold_layout_get_type())
/* enumerations from "amitk_tree_view.h" */
GType amitk_tree_view_mode_get_type (void);
#define AMITK_TYPE_TREE_VIEW_MODE (amitk_tree_view_mode_get_type())
G_END_DECLS

#endif /* __AMITK_TYPE_BUILTINS_H__ */



