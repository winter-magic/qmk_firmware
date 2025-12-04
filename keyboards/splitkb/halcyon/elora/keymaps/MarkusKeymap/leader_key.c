



#include "quantum.h"

bool my_leader_add_user(uint16_t keycode) {
	
	if (leader_sequence_one_key(KC_X)) {
        SEND_STRING(SS_LCTL(SS_TAP(X_X)));
		return true;
    } else if (leader_sequence_one_key(KC_C)) {
        SEND_STRING(SS_LCTL(SS_TAP(X_C)));
		return true;
    } else if (leader_sequence_one_key(KC_V)) {
        SEND_STRING(SS_LCTL(SS_TAP(X_V)));
		return true;
    } else if (leader_sequence_four_keys(KC_L, KC_O,KC_C,KC_K)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_L)));
		return true;
    } 
	
	
	
    // Information Commands (i)
    if (leader_sequence_two_keys(KC_I, KC_E)) {
        // Show Error Description
        SEND_STRING(SS_LSFT(SS_TAP(X_F2)));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_T)) {
        // Expression Type Info
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_P))));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_P)) {
        // Parameter Info
        SEND_STRING(SS_LCTL(SS_TAP(X_P)));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_J)) {
        // Quick Java Doc
        SEND_STRING(SS_LCTL(SS_TAP(X_Q)));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_F)) {
        // File Structure Popup
        SEND_STRING(SS_LCTL(SS_TAP(X_F12)));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_U)) {
        // Show Usages
        SEND_STRING(SS_LALT(SS_TAP(X_F7)));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_H)) {
        // Call Hierarchy
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_H))));
		return true;
    } else if (leader_sequence_two_keys(KC_I, KC_M)) {
        // Method Hierarchy
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_H))));
		return true;
    }
    
    // Window Splits (w)
    else if (leader_sequence_two_keys(KC_W, KC_V)) {
        // Split Vertically
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_BSLS))));
		return true;
    } else if (leader_sequence_two_keys(KC_W, KC_H)) {
        // Split Horizontally
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_MINS))));
		return true;
    } else if (leader_sequence_two_keys(KC_W, KC_U)) {
        // Unsplit
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F4))));
		return true;
    } else if (leader_sequence_two_keys(KC_W, KC_M)) {
        // Move Editor to Opposite Tab Group
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F6))));
		return true;
    }
    
    // Tab Navigation (t)
    else if (leader_sequence_two_keys(KC_T, KC_P)) {
        // Pin Active Tab
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_P))));
		return true;
    } else if (leader_sequence_two_keys(KC_T, KC_X)) {
        // Close Current Tab
        SEND_STRING(SS_LCTL(SS_TAP(X_F4)));
		return true;
    } else if (leader_sequence_two_keys(KC_T, KC_O)) {
        // Close All But Active
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_W))));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_1)) {
        // Go to Tab 1
        SEND_STRING(SS_LALT(SS_TAP(X_1)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_2)) {
        SEND_STRING(SS_LALT(SS_TAP(X_2)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_3)) {
        SEND_STRING(SS_LALT(SS_TAP(X_3)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_4)) {
        SEND_STRING(SS_LALT(SS_TAP(X_4)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_5)) {
        SEND_STRING(SS_LALT(SS_TAP(X_5)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_6)) {
        SEND_STRING(SS_LALT(SS_TAP(X_6)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_7)) {
        SEND_STRING(SS_LALT(SS_TAP(X_7)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_8)) {
        SEND_STRING(SS_LALT(SS_TAP(X_8)));
		return true;
    } else if (leader_sequence_three_keys(KC_T, KC_G, KC_9)) {
        SEND_STRING(SS_LALT(SS_TAP(X_9)));
		return true;
    }
    
   
    
    // File Navigation (f)
    else if (leader_sequence_two_keys(KC_F, KC_G)) {
        // Go To File
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_N))));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_R)) {
        // Recent Files
        SEND_STRING(SS_LCTL(SS_TAP(X_E)));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_C)) {
        // Find In Path
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F))));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_L)) {
        // Recent Locations
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_E))));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_S)) {
        // New Scratch File
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_INS)))));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_Y)) {
        // Copy Absolute Path
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_C)))));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_H)) {
        // Show Local History
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_H))));
		return true;
    } else if (leader_sequence_two_keys(KC_F, KC_F)) {
        // Show File Path
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_F12))));
		return true;
    }
    
    // Run Actions (r)
    else if (leader_sequence_two_keys(KC_R, KC_M)) {
        // Run Menu
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_F10))));
		return true;
    } else if (leader_sequence_two_keys(KC_R, KC_N)) {
        // Run Class
        SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
		return true;
    } else if (leader_sequence_two_keys(KC_R, KC_C)) {
        // Context Run
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F10))));
		return true;
    } else if (leader_sequence_two_keys(KC_R, KC_R)) {
        // Rerun
        SEND_STRING(SS_LCTL(SS_TAP(X_F5)));
		return true;
    } else if (leader_sequence_two_keys(KC_R, KC_T)) {
        // Run Tests
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F10))));
		return true;
    } else if (leader_sequence_two_keys(KC_R, KC_S)) {
        // Stop
        SEND_STRING(SS_LCTL(SS_TAP(X_F2)));
		return true;
    }
	
	 // Display Options (D)
    else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Toggle Distraction Free Mode
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F12))));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_Z)) {
        // Toggle Zen Mode
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_F12)))));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_F)) {
        // Toggle Full Screen
        SEND_STRING(SS_TAP(X_F11));
		return true;
    }
    
    // Debugging (d)
    else if (leader_sequence_two_keys(KC_D, KC_X)) {
        // Debug
        SEND_STRING(SS_LSFT(SS_TAP(X_F9)));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_C)) {
        // Context Debug
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F9))));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_V)) {
        // View Breakpoints
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F8))));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_T)) {
        // Toggle Line Breakpoint
        SEND_STRING(SS_LCTL(SS_TAP(X_F8)));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_I)) {
        // Step Into
        SEND_STRING(SS_TAP(X_F7));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_O)) {
        // Step Over
        SEND_STRING(SS_TAP(X_F8));
		return true;
    } else if (leader_sequence_two_keys(KC_D, KC_R)) {
        // Resume
        SEND_STRING(SS_TAP(X_F9));
		return true;
    }
    
    // Language/Refactoring (l)
    else if (leader_sequence_two_keys(KC_L, KC_L)) {
        // Quick List Popup
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT(SS_TAP(X_T)))));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_R)) {
        // Rename
        SEND_STRING(SS_LSFT(SS_TAP(X_F6)));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_C)) {
        // Change Signature
        SEND_STRING(SS_LCTL(SS_TAP(X_F6)));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_V)) {
        // Introduce Variable
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_V))));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_I)) {
        // Inline
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_N))));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_F)) {
        // Introduce Field
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_F))));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_M)) {
        // Extract Method
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_M))));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_A)) {
        // Show Intention Actions
        SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
		return true;
    } else if (leader_sequence_two_keys(KC_L, KC_G)) {
        // Generate
        SEND_STRING(SS_LALT(SS_TAP(X_INS)));
		return true;
    }
    
    // Bookmarks (b)
    else if (leader_sequence_two_keys(KC_B, KC_B)) {
        // Toggle Bookmark
        SEND_STRING(SS_TAP(X_F11));
		return true;
    } else if (leader_sequence_two_keys(KC_B, KC_S)) {
        // Show Bookmarks
        SEND_STRING(SS_LSFT(SS_TAP(X_F11)));
		return true;
    } else if (leader_sequence_two_keys(KC_B, KC_N)) {
        // Next Bookmark
        SEND_STRING(SS_LCTL(SS_TAP(X_F11)));
		return true;
    } else if (leader_sequence_two_keys(KC_B, KC_P)) {
        // Previous Bookmark
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F11))));
		return true;
    }
    
    // Go To (g)
    else if (leader_sequence_two_keys(KC_G, KC_D)) {
        // Go To Declaration
        SEND_STRING(SS_LCTL(SS_TAP(X_B)));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_I)) {
        // Go To Implementation
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_B))));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_O)) {
        // Go To Super Method
        SEND_STRING(SS_LCTL(SS_TAP(X_U)));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_T)) {
        // Go To Test
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_T))));
		return true;
    }
	
	// Git (G)
    else if (leader_sequence_two_keys(KC_G, KC_C)) {
        // Show Local Changes
        SEND_STRING(SS_LALT(SS_TAP(X_9)));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_B)) {
        // Git Branches
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_GRV))));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_P)) {
        // Push
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_K))));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_G)) {
        // Commit
        SEND_STRING(SS_LCTL(SS_TAP(X_K)));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_F)) {
        // Fetch
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_F))));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_A)) {
        // Annotate
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT(SS_TAP(X_A)))));
		return true;
    } else if (leader_sequence_two_keys(KC_G, KC_U)) {
        // Update Project
        SEND_STRING(SS_LCTL(SS_TAP(X_T)));
		return true;
    }
    
    // Search (s)
    else if (leader_sequence_two_keys(KC_S, KC_S)) {
        // Search Everywhere (Double Shift)
        SEND_STRING(SS_TAP(X_LSFT));
		wait_ms(25);
		SEND_STRING(SS_TAP(X_LSFT));
		return true;
    } else if (leader_sequence_two_keys(KC_S, KC_U)) {
        // Find Usages
        SEND_STRING(SS_LALT(SS_TAP(X_F7)));
		return true;
    } else if (leader_sequence_two_keys(KC_S, KC_A)) {
        // Go To Action
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_A))));
		return true;
    } else if (leader_sequence_two_keys(KC_S, KC_C)) {
        // Go To Class
        SEND_STRING(SS_LCTL(SS_TAP(X_N)));
		return true;
    } else if (leader_sequence_two_keys(KC_S, KC_F)) {
        // Go To File
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_N))));
		return true;
    } else if (leader_sequence_two_keys(KC_S, KC_T)) {
        // Text Search
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_F))));
		return true;
    }
    
	return false;
}