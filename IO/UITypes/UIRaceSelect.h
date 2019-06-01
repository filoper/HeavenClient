//////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright © 2015-2016 Daniel Allendorf                                   //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../UIElement.h"

#include "../Components/Textfield.h"
#include "../Template/BoolPair.h"

namespace jrc
{
	// Race selection screen.
	class UIRaceSelect : public UIElement
	{
	public:
		static constexpr Type TYPE = RACESELECT;
		static constexpr bool FOCUSED = false;
		static constexpr bool TOGGLED = false;

		UIRaceSelect();

		void draw(float inter) const override;
		void update() override;

		Cursor::State send_cursor(bool clicked, Point<int16_t> cursorpos) override;
		void send_key(int32_t keycode, bool pressed) override;

		void send_naming_result(bool nameused);

	protected:
		Button::State button_pressed(uint16_t buttonid) override;

	private:
		void select_class(uint8_t index);
		void show_charselect();
		Point<int16_t> get_class_pos(size_t index) const;

		static constexpr uint8_t INDEX_COUNT = 5;
		static constexpr uint8_t CLASS_COUNT = 26;

		enum Buttons : uint16_t
		{
			BACK,
			MAKE,
			LEFT,
			RIGHT,
			CLASS0,
			CLASS1,
			CLASS2,
			CLASS3,
			CLASS4
		};

		enum Classes : uint8_t
		{
			RESISTANCE,
			EXPLORER,
			CYGNUSKNIGHTS,
			ARAN,
			EVAN,
			MERCEDES,
			DEMON,
			PHANTOM,
			DUALBLADE,
			MIHILE,
			LUMINOUS,
			KAISER,
			ANGELICBUSTER,
			CANNONEER,
			XENON,
			ZERO,
			SHADE,
			JETT,
			HAYATO,
			KANNA,
			CHASE,
			PINKBEAN,
			KINESIS,
			CADENA,
			ILLIUM,
			ARK,
		};

		Text version;
		Point<int16_t> screen_adj;
		Point<int16_t> pos;
		Point<int16_t> posZero;
		nl::node order;
		nl::node hotlist;
		nl::node newlist;
		nl::node bgm;
		Sprite hotlabel;
		Sprite hotlabelZero;
		Sprite newlabel;
		Sprite hotbtn;
		Sprite newbtn;
		uint8_t class_index[INDEX_COUNT];
		bool mouseover[INDEX_COUNT];
		uint8_t selected_class;
		uint8_t index_shift;
		uint16_t selected_index;
		bool class_isdisabled[CLASS_COUNT];
		BoolPair<Texture> class_disabled[CLASS_COUNT];
		BoolPair<Texture> class_normal[CLASS_COUNT];
		Texture class_background[CLASS_COUNT];
		Texture class_details[CLASS_COUNT];
		Texture class_title[CLASS_COUNT];
		Texture back;
		Texture backZero;
		Sprite back_ani;
		Texture class_details_background;
		Texture class_details_backgroundZero;
	};
}