#pragma once
//
// (c)2019 by Lucky Resistor. See LICENSE for details.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//


#include "hal-common/StatusTools.hpp"
#include "hal-common/String.hpp"
#include "hal-common/Direction.hpp"
#include "hal-common/WritingDirection.hpp"


namespace lr {
namespace lcd {


/// The abstract interface for LCD character displays.
///
/// This interface assumes an LCD display with a fixed number of columns
/// and rows. There is a cursor which can be placed at a random location
/// on the display. Writing strings to the display will start writing
/// them at the current cursor location.
///
class CharacterDisplay
{
public:
    /// The status for calls to this interface.
    ///
    using Status = CallStatus;
    
    /// The scroll direction.
    ///
    using ScrollDirection = Direction;

    /// The cursor mode.
    ///
    enum class CursorMode : uint8_t {
        Off, ///< No cursor.
        Line, ///< A line.
        Block ///< A (blinking) block.
    };
        
public: // Required functions for each implementation.
    /// Reset the display.
    ///
    /// This method will reset the display to a defined initial state.
    /// It should be the same state after the display is initialized using
    /// the `initialize()` method.
    ///
    /// - Screen empty.
    /// - Cursor at position 0, 0.
    /// - Display not shifted.
    /// - Cursor not visible (Off).
    /// - Writing direction left to right.
    /// - Auto scroll off.
    ///
    /// The backlight is not affected by this method.
    ///
    virtual Status reset() = 0;
    
    /// Clear the display.
    ///
    /// This will clear the display and set the cursor to position 0,0.
    ///
    /// @return The status of the call.
    ///
    virtual Status clear() = 0;
    
    /// Reset the cursor position to 0,0.
    ///
    /// @return The status of the call.
    ///
    virtual Status cursorReset() = 0;
    
    /// Set the cursor to the given location.
    ///
    /// @param x The x position of the cursor.
    /// @param y The y position of the cursor.
    /// @return The status of the call.
    ///
    virtual Status setCursor(uint8_t x, uint8_t y) = 0;
    
    /// Write a single character to the display.
    ///
    /// This method does not require a special handling for line breaks of the display. The text is written
    /// sequentially in the chosen direction to the display memory. You have to use `setCursor` to change
    /// the line or cursor position in a logical way.
    ///
    /// @param c The character to write.
    /// @return The status of the call.
    ///
    virtual Status writeChar(char c) = 0;
    
    /// Write text to the display.
    ///
    /// This method does not require a special handling for line breaks of the display. The text is written
    /// sequentially in the chosen direction to the display memory. You have to use `setCursor` to change
    /// the line or cursor position in a logical way.
    ///
    /// @param text The text to write.
    /// @return The status of the call.
    ///
    virtual Status writeText(const String &text) = 0;

    /// Write text to the display.
    ///
    /// This method does not require a special handling for line breaks of the display. The text is written
    /// sequentially in the chosen direction to the display memory. You have to use `setCursor` to change
    /// the line or cursor position in a logical way.
    ///
    /// @param text The text to write.
    /// @return The status of the call.
    ///
    virtual Status writeText(const char *text) = 0;

public: // Optional functions, see implementation if supported.
    /// Enable/disable the display.
    ///
    /// @param enabled `true` if the display shall be enabled.
    /// @return The status of the call.
    ///
    virtual Status setEnabled(bool enabled) = 0;
    
    /// Set the cursor mode.
    ///
    /// @param mode The mode for the cursor.
    /// @return The status of the call.
    ///
    virtual Status setCursorMode(CursorMode mode) = 0;
    
    /// Enable the backlight of the display.
    ///
    /// @param enabled `true` if the backlight shall be enabled.
    /// @return The status of the call.
    ///
    virtual Status setBacklightEnabled(bool enabled) = 0;
    
    /// Set the writing direction.
    ///
    /// @param writingDirection The new writing direction.
    /// @return The status of the call.
    ///
    virtual Status setWritingDirection(WritingDirection writingDirection) = 0;

    /// Set if automatic scrolling is enabled.
    ///
    /// @param enabled `true` if automatic scrolling shall be enabled.
    /// @return The status of the call.
    ///
    virtual Status setAutoScrollEnabled(bool enabled) = 0;
    
    /// Scroll the display in the given direction.
    ///
    /// Not all scroll directions may be supported by the implementation.
    ///
    /// @param scrollDirection The direction to scroll the display.
    /// @return The status of the call.
    ///
    virtual Status scroll(ScrollDirection scrollDirection) = 0;    
};


}
}

