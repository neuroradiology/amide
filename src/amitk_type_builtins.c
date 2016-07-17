


#include <gtk/gtk.h>
#include "amide_config.h"
#include "amitk_common.h"
#include "amitk_canvas.h"
#include "amitk_data_set.h"
#include "amitk_filter.h"
#include "amitk_object.h"
#include "amitk_point.h"
#include "amitk_raw_data.h"
#include "amitk_roi.h"
#include "amitk_space.h"
#include "amitk_threshold.h"
#include "amitk_tree_view.h"

/* enumerations from "amitk_canvas.h" */
GType
amitk_canvas_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_CANVAS_TYPE_NORMAL, "AMITK_CANVAS_TYPE_NORMAL", "normal" },
      { AMITK_CANVAS_TYPE_FLY_THROUGH, "AMITK_CANVAS_TYPE_FLY_THROUGH", "fly-through" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkCanvasType", values);
  }
  return etype;
}
GType
amitk_canvas_target_action_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_CANVAS_TARGET_ACTION_HIDE, "AMITK_CANVAS_TARGET_ACTION_HIDE", "hide" },
      { AMITK_CANVAS_TARGET_ACTION_SHOW, "AMITK_CANVAS_TARGET_ACTION_SHOW", "show" },
      { AMITK_CANVAS_TARGET_ACTION_LEAVE, "AMITK_CANVAS_TARGET_ACTION_LEAVE", "leave" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkCanvasTargetAction", values);
  }
  return etype;
}

/* enumerations from "amitk_color_table.h" */
GType
amitk_color_table_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_COLOR_TABLE_BW_LINEAR, "AMITK_COLOR_TABLE_BW_LINEAR", "bw-linear" },
      { AMITK_COLOR_TABLE_WB_LINEAR, "AMITK_COLOR_TABLE_WB_LINEAR", "wb-linear" },
      { AMITK_COLOR_TABLE_BWB_LINEAR, "AMITK_COLOR_TABLE_BWB_LINEAR", "bwb-linear" },
      { AMITK_COLOR_TABLE_WBW_LINEAR, "AMITK_COLOR_TABLE_WBW_LINEAR", "wbw-linear" },
      { AMITK_COLOR_TABLE_RED_TEMP, "AMITK_COLOR_TABLE_RED_TEMP", "red-temp" },
      { AMITK_COLOR_TABLE_INV_RED_TEMP, "AMITK_COLOR_TABLE_INV_RED_TEMP", "inv-red-temp" },
      { AMITK_COLOR_TABLE_BLUE_TEMP, "AMITK_COLOR_TABLE_BLUE_TEMP", "blue-temp" },
      { AMITK_COLOR_TABLE_INV_BLUE_TEMP, "AMITK_COLOR_TABLE_INV_BLUE_TEMP", "inv-blue-temp" },
      { AMITK_COLOR_TABLE_GREEN_TEMP, "AMITK_COLOR_TABLE_GREEN_TEMP", "green-temp" },
      { AMITK_COLOR_TABLE_INV_GREEN_TEMP, "AMITK_COLOR_TABLE_INV_GREEN_TEMP", "inv-green-temp" },
      { AMITK_COLOR_TABLE_HOT_METAL, "AMITK_COLOR_TABLE_HOT_METAL", "hot-metal" },
      { AMITK_COLOR_TABLE_INV_HOT_METAL, "AMITK_COLOR_TABLE_INV_HOT_METAL", "inv-hot-metal" },
      { AMITK_COLOR_TABLE_HOT_METAL_CONTOUR, "AMITK_COLOR_TABLE_HOT_METAL_CONTOUR", "hot-metal-contour" },
      { AMITK_COLOR_TABLE_INV_HOT_METAL_CONTOUR, "AMITK_COLOR_TABLE_INV_HOT_METAL_CONTOUR", "inv-hot-metal-contour" },
      { AMITK_COLOR_TABLE_HOT_BLUE, "AMITK_COLOR_TABLE_HOT_BLUE", "hot-blue" },
      { AMITK_COLOR_TABLE_INV_HOT_BLUE, "AMITK_COLOR_TABLE_INV_HOT_BLUE", "inv-hot-blue" },
      { AMITK_COLOR_TABLE_HOT_GREEN, "AMITK_COLOR_TABLE_HOT_GREEN", "hot-green" },
      { AMITK_COLOR_TABLE_INV_HOT_GREEN, "AMITK_COLOR_TABLE_INV_HOT_GREEN", "inv-hot-green" },
      { AMITK_COLOR_TABLE_SPECTRUM, "AMITK_COLOR_TABLE_SPECTRUM", "spectrum" },
      { AMITK_COLOR_TABLE_INV_SPECTRUM, "AMITK_COLOR_TABLE_INV_SPECTRUM", "inv-spectrum" },
      { AMITK_COLOR_TABLE_NIH_WHITE, "AMITK_COLOR_TABLE_NIH_WHITE", "nih-white" },
      { AMITK_COLOR_TABLE_INV_NIH_WHITE, "AMITK_COLOR_TABLE_INV_NIH_WHITE", "inv-nih-white" },
      { AMITK_COLOR_TABLE_NIH, "AMITK_COLOR_TABLE_NIH", "nih" },
      { AMITK_COLOR_TABLE_INV_NIH, "AMITK_COLOR_TABLE_INV_NIH", "inv-nih" },
      { AMITK_COLOR_TABLE_NUM, "AMITK_COLOR_TABLE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkColorTable", values);
  }
  return etype;
}

/* enumerations from "amitk_common.h" */
GType
amitk_layout_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_LAYOUT_LINEAR, "AMITK_LAYOUT_LINEAR", "linear" },
      { AMITK_LAYOUT_ORTHOGONAL, "AMITK_LAYOUT_ORTHOGONAL", "orthogonal" },
      { AMITK_LAYOUT_NUM, "AMITK_LAYOUT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkLayout", values);
  }
  return etype;
}
GType
amitk_panel_layout_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_PANEL_LAYOUT_MIXED, "AMITK_PANEL_LAYOUT_MIXED", "mixed" },
      { AMITK_PANEL_LAYOUT_LINEAR_X, "AMITK_PANEL_LAYOUT_LINEAR_X", "linear-x" },
      { AMITK_PANEL_LAYOUT_LINEAR_Y, "AMITK_PANEL_LAYOUT_LINEAR_Y", "linear-y" },
      { AMITK_PANEL_LAYOUT_NUM, "AMITK_PANEL_LAYOUT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkPanelLayout", values);
  }
  return etype;
}
GType
amitk_view_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_VIEW_MODE_SINGLE, "AMITK_VIEW_MODE_SINGLE", "single" },
      { AMITK_VIEW_MODE_LINKED_2WAY, "AMITK_VIEW_MODE_LINKED_2WAY", "linked-2way" },
      { AMITK_VIEW_MODE_LINKED_3WAY, "AMITK_VIEW_MODE_LINKED_3WAY", "linked-3way" },
      { AMITK_VIEW_MODE_NUM, "AMITK_VIEW_MODE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkViewMode", values);
  }
  return etype;
}
GType
amitk_modality_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_MODALITY_PET, "AMITK_MODALITY_PET", "pet" },
      { AMITK_MODALITY_SPECT, "AMITK_MODALITY_SPECT", "spect" },
      { AMITK_MODALITY_CT, "AMITK_MODALITY_CT", "ct" },
      { AMITK_MODALITY_MRI, "AMITK_MODALITY_MRI", "mri" },
      { AMITK_MODALITY_OTHER, "AMITK_MODALITY_OTHER", "other" },
      { AMITK_MODALITY_NUM, "AMITK_MODALITY_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkModality", values);
  }
  return etype;
}
GType
amitk_limit_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_LIMIT_MIN, "AMITK_LIMIT_MIN", "min" },
      { AMITK_LIMIT_MAX, "AMITK_LIMIT_MAX", "max" },
      { AMITK_LIMIT_NUM, "AMITK_LIMIT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkLimit", values);
  }
  return etype;
}
GType
amitk_window_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_WINDOW_ABDOMEN, "AMITK_WINDOW_ABDOMEN", "abdomen" },
      { AMITK_WINDOW_BRAIN, "AMITK_WINDOW_BRAIN", "brain" },
      { AMITK_WINDOW_EXTREMITIES, "AMITK_WINDOW_EXTREMITIES", "extremities" },
      { AMITK_WINDOW_LIVER, "AMITK_WINDOW_LIVER", "liver" },
      { AMITK_WINDOW_LUNG, "AMITK_WINDOW_LUNG", "lung" },
      { AMITK_WINDOW_PELVIS_SOFT_TISSUE, "AMITK_WINDOW_PELVIS_SOFT_TISSUE", "pelvis-soft-tissue" },
      { AMITK_WINDOW_SKULL_BASE, "AMITK_WINDOW_SKULL_BASE", "skull-base" },
      { AMITK_WINDOW_SPINE_A, "AMITK_WINDOW_SPINE_A", "spine-a" },
      { AMITK_WINDOW_SPINE_B, "AMITK_WINDOW_SPINE_B", "spine-b" },
      { AMITK_WINDOW_THORAX_SOFT_TISSUE, "AMITK_WINDOW_THORAX_SOFT_TISSUE", "thorax-soft-tissue" },
      { AMITK_WINDOW_NUM, "AMITK_WINDOW_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkWindow", values);
  }
  return etype;
}
GType
amitk_threshold_style_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLD_STYLE_MIN_MAX, "AMITK_THRESHOLD_STYLE_MIN_MAX", "min-max" },
      { AMITK_THRESHOLD_STYLE_CENTER_WIDTH, "AMITK_THRESHOLD_STYLE_CENTER_WIDTH", "center-width" },
      { AMITK_THRESHOLD_STYLE_NUM, "AMITK_THRESHOLD_STYLE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholdStyle", values);
  }
  return etype;
}
GType
amitk_help_info_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_HELP_INFO_BLANK, "AMITK_HELP_INFO_BLANK", "blank" },
      { AMITK_HELP_INFO_CANVAS_DATA_SET, "AMITK_HELP_INFO_CANVAS_DATA_SET", "canvas-data-set" },
      { AMITK_HELP_INFO_CANVAS_ROI, "AMITK_HELP_INFO_CANVAS_ROI", "canvas-roi" },
      { AMITK_HELP_INFO_CANVAS_FIDUCIAL_MARK, "AMITK_HELP_INFO_CANVAS_FIDUCIAL_MARK", "canvas-fiducial-mark" },
      { AMITK_HELP_INFO_CANVAS_STUDY, "AMITK_HELP_INFO_CANVAS_STUDY", "canvas-study" },
      { AMITK_HELP_INFO_CANVAS_ISOCONTOUR_ROI, "AMITK_HELP_INFO_CANVAS_ISOCONTOUR_ROI", "canvas-isocontour-roi" },
      { AMITK_HELP_INFO_CANVAS_FREEHAND_ROI, "AMITK_HELP_INFO_CANVAS_FREEHAND_ROI", "canvas-freehand-roi" },
      { AMITK_HELP_INFO_CANVAS_DRAWING_MODE, "AMITK_HELP_INFO_CANVAS_DRAWING_MODE", "canvas-drawing-mode" },
      { AMITK_HELP_INFO_CANVAS_LINE_PROFILE, "AMITK_HELP_INFO_CANVAS_LINE_PROFILE", "canvas-line-profile" },
      { AMITK_HELP_INFO_CANVAS_NEW_ROI, "AMITK_HELP_INFO_CANVAS_NEW_ROI", "canvas-new-roi" },
      { AMITK_HELP_INFO_CANVAS_NEW_ISOCONTOUR_ROI, "AMITK_HELP_INFO_CANVAS_NEW_ISOCONTOUR_ROI", "canvas-new-isocontour-roi" },
      { AMITK_HELP_INFO_CANVAS_NEW_FREEHAND_ROI, "AMITK_HELP_INFO_CANVAS_NEW_FREEHAND_ROI", "canvas-new-freehand-roi" },
      { AMITK_HELP_INFO_CANVAS_CHANGE_ISOCONTOUR, "AMITK_HELP_INFO_CANVAS_CHANGE_ISOCONTOUR", "canvas-change-isocontour" },
      { AMITK_HELP_INFO_CANVAS_SHIFT_OBJECT, "AMITK_HELP_INFO_CANVAS_SHIFT_OBJECT", "canvas-shift-object" },
      { AMITK_HELP_INFO_CANVAS_ROTATE_OBJECT, "AMITK_HELP_INFO_CANVAS_ROTATE_OBJECT", "canvas-rotate-object" },
      { AMITK_HELP_INFO_TREE_VIEW_DATA_SET, "AMITK_HELP_INFO_TREE_VIEW_DATA_SET", "tree-view-data-set" },
      { AMITK_HELP_INFO_TREE_VIEW_ROI, "AMITK_HELP_INFO_TREE_VIEW_ROI", "tree-view-roi" },
      { AMITK_HELP_INFO_TREE_VIEW_FIDUCIAL_MARK, "AMITK_HELP_INFO_TREE_VIEW_FIDUCIAL_MARK", "tree-view-fiducial-mark" },
      { AMITK_HELP_INFO_TREE_VIEW_STUDY, "AMITK_HELP_INFO_TREE_VIEW_STUDY", "tree-view-study" },
      { AMITK_HELP_INFO_TREE_VIEW_NONE, "AMITK_HELP_INFO_TREE_VIEW_NONE", "tree-view-none" },
      { AMITK_HELP_INFO_UPDATE_LOCATION, "AMITK_HELP_INFO_UPDATE_LOCATION", "update-location" },
      { AMITK_HELP_INFO_UPDATE_THETA, "AMITK_HELP_INFO_UPDATE_THETA", "update-theta" },
      { AMITK_HELP_INFO_UPDATE_SHIFT, "AMITK_HELP_INFO_UPDATE_SHIFT", "update-shift" },
      { AMITK_HELP_INFO_NUM, "AMITK_HELP_INFO_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkHelpInfo", values);
  }
  return etype;
}

/* enumerations from "amitk_data_set.h" */
GType
amitk_operation_unary_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_OPERATION_UNARY_RESCALE, "AMITK_OPERATION_UNARY_RESCALE", "rescale" },
      { AMITK_OPERATION_UNARY_REMOVE_NEGATIVES, "AMITK_OPERATION_UNARY_REMOVE_NEGATIVES", "remove-negatives" },
      { AMITK_OPERATION_UNARY_NUM, "AMITK_OPERATION_UNARY_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkOperationUnary", values);
  }
  return etype;
}
GType
amitk_operation_binary_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_OPERATION_BINARY_ADD, "AMITK_OPERATION_BINARY_ADD", "add" },
      { AMITK_OPERATION_BINARY_SUB, "AMITK_OPERATION_BINARY_SUB", "sub" },
      { AMITK_OPERATION_BINARY_MULTIPLY, "AMITK_OPERATION_BINARY_MULTIPLY", "multiply" },
      { AMITK_OPERATION_BINARY_DIVISION, "AMITK_OPERATION_BINARY_DIVISION", "division" },
      { AMITK_OPERATION_BINARY_T2STAR, "AMITK_OPERATION_BINARY_T2STAR", "t2star" },
      { AMITK_OPERATION_BINARY_NUM, "AMITK_OPERATION_BINARY_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkOperationBinary", values);
  }
  return etype;
}
GType
amitk_interpolation_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_INTERPOLATION_NEAREST_NEIGHBOR, "AMITK_INTERPOLATION_NEAREST_NEIGHBOR", "nearest-neighbor" },
      { AMITK_INTERPOLATION_TRILINEAR, "AMITK_INTERPOLATION_TRILINEAR", "trilinear" },
      { AMITK_INTERPOLATION_NUM, "AMITK_INTERPOLATION_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkInterpolation", values);
  }
  return etype;
}
GType
amitk_rendering_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_RENDERING_MPR, "AMITK_RENDERING_MPR", "mpr" },
      { AMITK_RENDERING_MIP, "AMITK_RENDERING_MIP", "mip" },
      { AMITK_RENDERING_MINIP, "AMITK_RENDERING_MINIP", "minip" },
      { AMITK_RENDERING_NUM, "AMITK_RENDERING_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkRendering", values);
  }
  return etype;
}
GType
amitk_thresholding_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLDING_PER_SLICE, "AMITK_THRESHOLDING_PER_SLICE", "per-slice" },
      { AMITK_THRESHOLDING_PER_FRAME, "AMITK_THRESHOLDING_PER_FRAME", "per-frame" },
      { AMITK_THRESHOLDING_INTERPOLATE_FRAMES, "AMITK_THRESHOLDING_INTERPOLATE_FRAMES", "interpolate-frames" },
      { AMITK_THRESHOLDING_GLOBAL, "AMITK_THRESHOLDING_GLOBAL", "global" },
      { AMITK_THRESHOLDING_NUM, "AMITK_THRESHOLDING_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholding", values);
  }
  return etype;
}
GType
amitk_scaling_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_SCALING_TYPE_0D, "AMITK_SCALING_TYPE_0D", "0d" },
      { AMITK_SCALING_TYPE_1D, "AMITK_SCALING_TYPE_1D", "1d" },
      { AMITK_SCALING_TYPE_2D, "AMITK_SCALING_TYPE_2D", "2d" },
      { AMITK_SCALING_TYPE_0D_WITH_INTERCEPT, "AMITK_SCALING_TYPE_0D_WITH_INTERCEPT", "0d-with-intercept" },
      { AMITK_SCALING_TYPE_1D_WITH_INTERCEPT, "AMITK_SCALING_TYPE_1D_WITH_INTERCEPT", "1d-with-intercept" },
      { AMITK_SCALING_TYPE_2D_WITH_INTERCEPT, "AMITK_SCALING_TYPE_2D_WITH_INTERCEPT", "2d-with-intercept" },
      { AMITK_SCALING_TYPE_NUM, "AMITK_SCALING_TYPE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkScalingType", values);
  }
  return etype;
}
GType
amitk_conversion_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_CONVERSION_STRAIGHT, "AMITK_CONVERSION_STRAIGHT", "straight" },
      { AMITK_CONVERSION_PERCENT_ID_PER_CC, "AMITK_CONVERSION_PERCENT_ID_PER_CC", "percent-id-per-cc" },
      { AMITK_CONVERSION_SUV, "AMITK_CONVERSION_SUV", "suv" },
      { AMITK_CONVERSION_NUM, "AMITK_CONVERSION_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkConversion", values);
  }
  return etype;
}
GType
amitk_weight_unit_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_WEIGHT_UNIT_KILOGRAM, "AMITK_WEIGHT_UNIT_KILOGRAM", "kilogram" },
      { AMITK_WEIGHT_UNIT_GRAM, "AMITK_WEIGHT_UNIT_GRAM", "gram" },
      { AMITK_WEIGHT_UNIT_POUND, "AMITK_WEIGHT_UNIT_POUND", "pound" },
      { AMITK_WEIGHT_UNIT_OUNCE, "AMITK_WEIGHT_UNIT_OUNCE", "ounce" },
      { AMITK_WEIGHT_UNIT_NUM, "AMITK_WEIGHT_UNIT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkWeightUnit", values);
  }
  return etype;
}
GType
amitk_dose_unit_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_DOSE_UNIT_MEGABECQUEREL, "AMITK_DOSE_UNIT_MEGABECQUEREL", "megabecquerel" },
      { AMITK_DOSE_UNIT_MILLICURIE, "AMITK_DOSE_UNIT_MILLICURIE", "millicurie" },
      { AMITK_DOSE_UNIT_MICROCURIE, "AMITK_DOSE_UNIT_MICROCURIE", "microcurie" },
      { AMITK_DOSE_UNIT_NANOCURIE, "AMITK_DOSE_UNIT_NANOCURIE", "nanocurie" },
      { AMITK_DOSE_UNIT_NUM, "AMITK_DOSE_UNIT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkDoseUnit", values);
  }
  return etype;
}
GType
amitk_cylinder_unit_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_CYLINDER_UNIT_MEGABECQUEREL_PER_CC_IMAGE_UNIT, "AMITK_CYLINDER_UNIT_MEGABECQUEREL_PER_CC_IMAGE_UNIT", "megabecquerel-per-cc-image-unit" },
      { AMITK_CYLINDER_UNIT_MILLICURIE_PER_CC_IMAGE_UNIT, "AMITK_CYLINDER_UNIT_MILLICURIE_PER_CC_IMAGE_UNIT", "millicurie-per-cc-image-unit" },
      { AMITK_CYLINDER_UNIT_MICROCURIE_PER_CC_IMAGE_UNIT, "AMITK_CYLINDER_UNIT_MICROCURIE_PER_CC_IMAGE_UNIT", "microcurie-per-cc-image-unit" },
      { AMITK_CYLINDER_UNIT_NANOCURIE_PER_CC_IMAGE_UNIT, "AMITK_CYLINDER_UNIT_NANOCURIE_PER_CC_IMAGE_UNIT", "nanocurie-per-cc-image-unit" },
      { AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_MEGABECQUEREL, "AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_MEGABECQUEREL", "image-unit-cc-per-megabecquerel" },
      { AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_MILLICURIE, "AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_MILLICURIE", "image-unit-cc-per-millicurie" },
      { AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_MICROCURIE, "AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_MICROCURIE", "image-unit-cc-per-microcurie" },
      { AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_NANOCURIE, "AMITK_CYLINDER_UNIT_IMAGE_UNIT_CC_PER_NANOCURIE", "image-unit-cc-per-nanocurie" },
      { AMITK_CYLINDER_UNIT_NUM, "AMITK_CYLINDER_UNIT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkCylinderUnit", values);
  }
  return etype;
}
GType
amitk_subject_orientation_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_SUBJECT_ORIENTATION_UNKNOWN, "AMITK_SUBJECT_ORIENTATION_UNKNOWN", "unknown" },
      { AMITK_SUBJECT_ORIENTATION_SUPINE_HEADFIRST, "AMITK_SUBJECT_ORIENTATION_SUPINE_HEADFIRST", "supine-headfirst" },
      { AMITK_SUBJECT_ORIENTATION_SUPINE_FEETFIRST, "AMITK_SUBJECT_ORIENTATION_SUPINE_FEETFIRST", "supine-feetfirst" },
      { AMITK_SUBJECT_ORIENTATION_PRONE_HEADFIRST, "AMITK_SUBJECT_ORIENTATION_PRONE_HEADFIRST", "prone-headfirst" },
      { AMITK_SUBJECT_ORIENTATION_PRONE_FEETFIRST, "AMITK_SUBJECT_ORIENTATION_PRONE_FEETFIRST", "prone-feetfirst" },
      { AMITK_SUBJECT_ORIENTATION_RIGHT_DECUBITUS_HEADFIRST, "AMITK_SUBJECT_ORIENTATION_RIGHT_DECUBITUS_HEADFIRST", "right-decubitus-headfirst" },
      { AMITK_SUBJECT_ORIENTATION_RIGHT_DECUBITUS_FEETFIRST, "AMITK_SUBJECT_ORIENTATION_RIGHT_DECUBITUS_FEETFIRST", "right-decubitus-feetfirst" },
      { AMITK_SUBJECT_ORIENTATION_LEFT_DECUBITUS_HEADFIRST, "AMITK_SUBJECT_ORIENTATION_LEFT_DECUBITUS_HEADFIRST", "left-decubitus-headfirst" },
      { AMITK_SUBJECT_ORIENTATION_LEFT_DECUBITUS_FEETFIRST, "AMITK_SUBJECT_ORIENTATION_LEFT_DECUBITUS_FEETFIRST", "left-decubitus-feetfirst" },
      { AMITK_SUBJECT_ORIENTATION_NUM, "AMITK_SUBJECT_ORIENTATION_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkSubjectOrientation", values);
  }
  return etype;
}
GType
amitk_subject_sex_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_SUBJECT_SEX_UNKNOWN, "AMITK_SUBJECT_SEX_UNKNOWN", "unknown" },
      { AMITK_SUBJECT_SEX_MALE, "AMITK_SUBJECT_SEX_MALE", "male" },
      { AMITK_SUBJECT_SEX_FEMALE, "AMITK_SUBJECT_SEX_FEMALE", "female" },
      { AMITK_SUBJECT_SEX_NUM, "AMITK_SUBJECT_SEX_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkSubjectSex", values);
  }
  return etype;
}

/* enumerations from "amitk_filter.h" */
GType
amitk_filter_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_FILTER_GAUSSIAN, "AMITK_FILTER_GAUSSIAN", "gaussian" },
      { AMITK_FILTER_MEDIAN_LINEAR, "AMITK_FILTER_MEDIAN_LINEAR", "median-linear" },
      { AMITK_FILTER_MEDIAN_3D, "AMITK_FILTER_MEDIAN_3D", "median-3d" },
      { AMITK_FILTER_NUM, "AMITK_FILTER_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkFilter", values);
  }
  return etype;
}

/* enumerations from "amitk_object.h" */
GType
amitk_object_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_OBJECT_TYPE_STUDY, "AMITK_OBJECT_TYPE_STUDY", "study" },
      { AMITK_OBJECT_TYPE_DATA_SET, "AMITK_OBJECT_TYPE_DATA_SET", "data-set" },
      { AMITK_OBJECT_TYPE_FIDUCIAL_MARK, "AMITK_OBJECT_TYPE_FIDUCIAL_MARK", "fiducial-mark" },
      { AMITK_OBJECT_TYPE_ROI, "AMITK_OBJECT_TYPE_ROI", "roi" },
      { AMITK_OBJECT_TYPE_VOLUME, "AMITK_OBJECT_TYPE_VOLUME", "volume" },
      { AMITK_OBJECT_TYPE_NUM, "AMITK_OBJECT_TYPE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkObjectType", values);
  }
  return etype;
}
GType
amitk_selection_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_SELECTION_SELECTED_0, "AMITK_SELECTION_SELECTED_0", "selected-0" },
      { AMITK_SELECTION_SELECTED_1, "AMITK_SELECTION_SELECTED_1", "selected-1" },
      { AMITK_SELECTION_SELECTED_2, "AMITK_SELECTION_SELECTED_2", "selected-2" },
      { AMITK_SELECTION_NUM, "AMITK_SELECTION_NUM", "num" },
      { AMITK_SELECTION_ANY, "AMITK_SELECTION_ANY", "any" },
      { AMITK_SELECTION_ALL, "AMITK_SELECTION_ALL", "all" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkSelection", values);
  }
  return etype;
}

/* enumerations from "amitk_point.h" */
GType
amitk_view_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_VIEW_TRANSVERSE, "AMITK_VIEW_TRANSVERSE", "transverse" },
      { AMITK_VIEW_CORONAL, "AMITK_VIEW_CORONAL", "coronal" },
      { AMITK_VIEW_SAGITTAL, "AMITK_VIEW_SAGITTAL", "sagittal" },
      { AMITK_VIEW_NUM, "AMITK_VIEW_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkView", values);
  }
  return etype;
}
GType
amitk_axis_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_AXIS_X, "AMITK_AXIS_X", "x" },
      { AMITK_AXIS_Y, "AMITK_AXIS_Y", "y" },
      { AMITK_AXIS_Z, "AMITK_AXIS_Z", "z" },
      { AMITK_AXIS_NUM, "AMITK_AXIS_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkAxis", values);
  }
  return etype;
}
GType
amitk_dim_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_DIM_X, "AMITK_DIM_X", "x" },
      { AMITK_DIM_Y, "AMITK_DIM_Y", "y" },
      { AMITK_DIM_Z, "AMITK_DIM_Z", "z" },
      { AMITK_DIM_G, "AMITK_DIM_G", "g" },
      { AMITK_DIM_T, "AMITK_DIM_T", "t" },
      { AMITK_DIM_NUM, "AMITK_DIM_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkDim", values);
  }
  return etype;
}
GType
amitk_length_unit_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_LENGTH_UNIT_MM, "AMITK_LENGTH_UNIT_MM", "mm" },
      { AMITK_LENGTH_UNIT_CM, "AMITK_LENGTH_UNIT_CM", "cm" },
      { AMITK_LENGTH_UNIT_M, "AMITK_LENGTH_UNIT_M", "m" },
      { AMITK_LENGTH_UNIT_INCHES, "AMITK_LENGTH_UNIT_INCHES", "inches" },
      { AMITK_LENGTH_UNIT_FEET, "AMITK_LENGTH_UNIT_FEET", "feet" },
      { AMITK_LENGTH_UNIT_NUM, "AMITK_LENGTH_UNIT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkLengthUnit", values);
  }
  return etype;
}

/* enumerations from "amitk_preferences.h" */
GType
amitk_which_default_directory_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_WHICH_DEFAULT_DIRECTORY_NONE, "AMITK_WHICH_DEFAULT_DIRECTORY_NONE", "none" },
      { AMITK_WHICH_DEFAULT_DIRECTORY_SPECIFIED, "AMITK_WHICH_DEFAULT_DIRECTORY_SPECIFIED", "specified" },
      { AMITK_WHICH_DEFAULT_DIRECTORY_WORKING, "AMITK_WHICH_DEFAULT_DIRECTORY_WORKING", "working" },
      { AMITK_WHICH_DEFAULT_DIRECTORY_NUM, "AMITK_WHICH_DEFAULT_DIRECTORY_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkWhichDefaultDirectory", values);
  }
  return etype;
}

/* enumerations from "amitk_raw_data.h" */
GType
amitk_format_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_FORMAT_UBYTE, "AMITK_FORMAT_UBYTE", "ubyte" },
      { AMITK_FORMAT_SBYTE, "AMITK_FORMAT_SBYTE", "sbyte" },
      { AMITK_FORMAT_USHORT, "AMITK_FORMAT_USHORT", "ushort" },
      { AMITK_FORMAT_SSHORT, "AMITK_FORMAT_SSHORT", "sshort" },
      { AMITK_FORMAT_UINT, "AMITK_FORMAT_UINT", "uint" },
      { AMITK_FORMAT_SINT, "AMITK_FORMAT_SINT", "sint" },
      { AMITK_FORMAT_FLOAT, "AMITK_FORMAT_FLOAT", "float" },
      { AMITK_FORMAT_DOUBLE, "AMITK_FORMAT_DOUBLE", "double" },
      { AMITK_FORMAT_NUM, "AMITK_FORMAT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkFormat", values);
  }
  return etype;
}
GType
amitk_raw_format_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_RAW_FORMAT_UBYTE_8_NE, "AMITK_RAW_FORMAT_UBYTE_8_NE", "ubyte-8-ne" },
      { AMITK_RAW_FORMAT_SBYTE_8_NE, "AMITK_RAW_FORMAT_SBYTE_8_NE", "sbyte-8-ne" },
      { AMITK_RAW_FORMAT_USHORT_16_LE, "AMITK_RAW_FORMAT_USHORT_16_LE", "ushort-16-le" },
      { AMITK_RAW_FORMAT_SSHORT_16_LE, "AMITK_RAW_FORMAT_SSHORT_16_LE", "sshort-16-le" },
      { AMITK_RAW_FORMAT_UINT_32_LE, "AMITK_RAW_FORMAT_UINT_32_LE", "uint-32-le" },
      { AMITK_RAW_FORMAT_SINT_32_LE, "AMITK_RAW_FORMAT_SINT_32_LE", "sint-32-le" },
      { AMITK_RAW_FORMAT_FLOAT_32_LE, "AMITK_RAW_FORMAT_FLOAT_32_LE", "float-32-le" },
      { AMITK_RAW_FORMAT_DOUBLE_64_LE, "AMITK_RAW_FORMAT_DOUBLE_64_LE", "double-64-le" },
      { AMITK_RAW_FORMAT_USHORT_16_BE, "AMITK_RAW_FORMAT_USHORT_16_BE", "ushort-16-be" },
      { AMITK_RAW_FORMAT_SSHORT_16_BE, "AMITK_RAW_FORMAT_SSHORT_16_BE", "sshort-16-be" },
      { AMITK_RAW_FORMAT_UINT_32_BE, "AMITK_RAW_FORMAT_UINT_32_BE", "uint-32-be" },
      { AMITK_RAW_FORMAT_SINT_32_BE, "AMITK_RAW_FORMAT_SINT_32_BE", "sint-32-be" },
      { AMITK_RAW_FORMAT_FLOAT_32_BE, "AMITK_RAW_FORMAT_FLOAT_32_BE", "float-32-be" },
      { AMITK_RAW_FORMAT_DOUBLE_64_BE, "AMITK_RAW_FORMAT_DOUBLE_64_BE", "double-64-be" },
      { AMITK_RAW_FORMAT_UINT_32_PDP, "AMITK_RAW_FORMAT_UINT_32_PDP", "uint-32-pdp" },
      { AMITK_RAW_FORMAT_SINT_32_PDP, "AMITK_RAW_FORMAT_SINT_32_PDP", "sint-32-pdp" },
      { AMITK_RAW_FORMAT_FLOAT_32_PDP, "AMITK_RAW_FORMAT_FLOAT_32_PDP", "float-32-pdp" },
      { AMITK_RAW_FORMAT_ASCII_8_NE, "AMITK_RAW_FORMAT_ASCII_8_NE", "ascii-8-ne" },
      { AMITK_RAW_FORMAT_NUM, "AMITK_RAW_FORMAT_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkRawFormat", values);
  }
  return etype;
}

/* enumerations from "amitk_roi.h" */
GType
amitk_roi_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_ROI_TYPE_ELLIPSOID, "AMITK_ROI_TYPE_ELLIPSOID", "ellipsoid" },
      { AMITK_ROI_TYPE_CYLINDER, "AMITK_ROI_TYPE_CYLINDER", "cylinder" },
      { AMITK_ROI_TYPE_BOX, "AMITK_ROI_TYPE_BOX", "box" },
      { AMITK_ROI_TYPE_ISOCONTOUR_2D, "AMITK_ROI_TYPE_ISOCONTOUR_2D", "isocontour-2d" },
      { AMITK_ROI_TYPE_ISOCONTOUR_3D, "AMITK_ROI_TYPE_ISOCONTOUR_3D", "isocontour-3d" },
      { AMITK_ROI_TYPE_FREEHAND_2D, "AMITK_ROI_TYPE_FREEHAND_2D", "freehand-2d" },
      { AMITK_ROI_TYPE_FREEHAND_3D, "AMITK_ROI_TYPE_FREEHAND_3D", "freehand-3d" },
      { AMITK_ROI_TYPE_NUM, "AMITK_ROI_TYPE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkRoiType", values);
  }
  return etype;
}
GType
amitk_roi_isocontour_range_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_ROI_ISOCONTOUR_RANGE_ABOVE_MIN, "AMITK_ROI_ISOCONTOUR_RANGE_ABOVE_MIN", "above-min" },
      { AMITK_ROI_ISOCONTOUR_RANGE_BELOW_MAX, "AMITK_ROI_ISOCONTOUR_RANGE_BELOW_MAX", "below-max" },
      { AMITK_ROI_ISOCONTOUR_RANGE_BETWEEN_MIN_MAX, "AMITK_ROI_ISOCONTOUR_RANGE_BETWEEN_MIN_MAX", "between-min-max" },
      { AMITK_ROI_ISOCONTOUR_RANGE_NUM, "AMITK_ROI_ISOCONTOUR_RANGE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkRoiIsocontourRange", values);
  }
  return etype;
}

/* enumerations from "amitk_study.h" */
GType
amitk_fuse_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_FUSE_TYPE_BLEND, "AMITK_FUSE_TYPE_BLEND", "blend" },
      { AMITK_FUSE_TYPE_OVERLAY, "AMITK_FUSE_TYPE_OVERLAY", "overlay" },
      { AMITK_FUSE_TYPE_NUM, "AMITK_FUSE_TYPE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkFuseType", values);
  }
  return etype;
}

/* enumerations from "amitk_threshold.h" */
GType
amitk_threshold_scale_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLD_SCALE_FULL, "AMITK_THRESHOLD_SCALE_FULL", "full" },
      { AMITK_THRESHOLD_SCALE_SCALED, "AMITK_THRESHOLD_SCALE_SCALED", "scaled" },
      { AMITK_THRESHOLD_SCALE_NUM_SCALES, "AMITK_THRESHOLD_SCALE_NUM_SCALES", "num-scales" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholdScale", values);
  }
  return etype;
}
GType
amitk_threshold_arrow_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLD_ARROW_FULL_MIN, "AMITK_THRESHOLD_ARROW_FULL_MIN", "full-min" },
      { AMITK_THRESHOLD_ARROW_FULL_CENTER, "AMITK_THRESHOLD_ARROW_FULL_CENTER", "full-center" },
      { AMITK_THRESHOLD_ARROW_FULL_MAX, "AMITK_THRESHOLD_ARROW_FULL_MAX", "full-max" },
      { AMITK_THRESHOLD_ARROW_SCALED_MIN, "AMITK_THRESHOLD_ARROW_SCALED_MIN", "scaled-min" },
      { AMITK_THRESHOLD_ARROW_SCALED_CENTER, "AMITK_THRESHOLD_ARROW_SCALED_CENTER", "scaled-center" },
      { AMITK_THRESHOLD_ARROW_SCALED_MAX, "AMITK_THRESHOLD_ARROW_SCALED_MAX", "scaled-max" },
      { AMITK_THRESHOLD_ARROW_NUM_ARROWS, "AMITK_THRESHOLD_ARROW_NUM_ARROWS", "num-arrows" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholdArrow", values);
  }
  return etype;
}
GType
amitk_threshold_entry_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLD_ENTRY_MAX_ABSOLUTE, "AMITK_THRESHOLD_ENTRY_MAX_ABSOLUTE", "max-absolute" },
      { AMITK_THRESHOLD_ENTRY_MAX_PERCENT, "AMITK_THRESHOLD_ENTRY_MAX_PERCENT", "max-percent" },
      { AMITK_THRESHOLD_ENTRY_MIN_ABSOLUTE, "AMITK_THRESHOLD_ENTRY_MIN_ABSOLUTE", "min-absolute" },
      { AMITK_THRESHOLD_ENTRY_MIN_PERCENT, "AMITK_THRESHOLD_ENTRY_MIN_PERCENT", "min-percent" },
      { AMITK_THRESHOLD_ENTRY_NUM_ENTRIES, "AMITK_THRESHOLD_ENTRY_NUM_ENTRIES", "num-entries" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholdEntry", values);
  }
  return etype;
}
GType
amitk_threshold_line_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLD_LINE_MAX, "AMITK_THRESHOLD_LINE_MAX", "max" },
      { AMITK_THRESHOLD_LINE_CENTER, "AMITK_THRESHOLD_LINE_CENTER", "center" },
      { AMITK_THRESHOLD_LINE_MIN, "AMITK_THRESHOLD_LINE_MIN", "min" },
      { AMITK_THRESHOLD_LINE_NUM_LINES, "AMITK_THRESHOLD_LINE_NUM_LINES", "num-lines" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholdLine", values);
  }
  return etype;
}
GType
amitk_threshold_layout_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_THRESHOLD_BOX_LAYOUT, "AMITK_THRESHOLD_BOX_LAYOUT", "box-layout" },
      { AMITK_THRESHOLD_LINEAR_LAYOUT, "AMITK_THRESHOLD_LINEAR_LAYOUT", "linear-layout" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkThresholdLayout", values);
  }
  return etype;
}

/* enumerations from "amitk_tree_view.h" */
GType
amitk_tree_view_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { AMITK_TREE_VIEW_MODE_MAIN, "AMITK_TREE_VIEW_MODE_MAIN", "main" },
      { AMITK_TREE_VIEW_MODE_SINGLE_SELECTION, "AMITK_TREE_VIEW_MODE_SINGLE_SELECTION", "single-selection" },
      { AMITK_TREE_VIEW_MODE_MULTIPLE_SELECTION, "AMITK_TREE_VIEW_MODE_MULTIPLE_SELECTION", "multiple-selection" },
      { AMITK_TREE_VIEW_MODE_NUM, "AMITK_TREE_VIEW_MODE_NUM", "num" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("AmitkTreeViewMode", values);
  }
  return etype;
}



