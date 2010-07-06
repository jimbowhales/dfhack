#ifndef CL_MOD_POSITION
#define CL_MOD_POSITION
/*
* View position and size and cursor position
*/
#include "dfhack/DFExport.h"
#include "dfhack/DFModule.h"
namespace DFHack
{
    #define NUM_HOTKEYS 16
    struct t_hotkey
    {
        char name[10];
        int16_t mode;
        int32_t x;
        int32_t y;
        int32_t z;
    };

    class DFContextShared;
    class DFHACK_EXPORT Position : public Module
    {
        public:

        Position(DFContextShared * d);
        ~Position();
        bool Finish(){return true;};
        /*
        * Cursor and window coords
        */
        bool getViewCoords (int32_t &x, int32_t &y, int32_t &z);
        bool setViewCoords (const int32_t x, const int32_t y, const int32_t z);

        bool getCursorCoords (int32_t &x, int32_t &y, int32_t &z);
        bool setCursorCoords (const int32_t x, const int32_t y, const int32_t z);

        /*
        * Hotkeys (DF's zoom locations)
        */
        bool ReadHotkeys(t_hotkey hotkeys[]);

        /*
        * Window size in tiles
        */
        bool getWindowSize(int32_t & width, int32_t & height);

        private:
        struct Private;
        Private *d;
    };
}
#endif
