#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM, wdw_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT, wdw_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM, wdw_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_EXPRESS_ELEVATOR, wdw_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, wdw_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ROTATING_PLATFORM, wdw_geo_000640), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 100, 0),
		OBJECT(MODEL_NONE, 0, 100, 0, 0, 0, 0, (0x0A << 16), bhvSpinAirborneWarp),
		TERRAIN(wdw_area_1_collision),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 100, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};