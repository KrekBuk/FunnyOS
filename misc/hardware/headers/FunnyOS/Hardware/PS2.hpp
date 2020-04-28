#ifndef FUNNYOS_MISC_HARDWARE_HEADERS_FUNNYOS_HARDWARE_PS2_HPP
#define FUNNYOS_MISC_HARDWARE_HEADERS_FUNNYOS_HARDWARE_PS2_HPP

#include <FunnyOS/Stdlib/IntegerTypes.hpp>

namespace FunnyOS::HW::PS2 {

    /**
     * All scan codes in a decoded form. Can be read via TryReadScanCode
     */
    enum class ScanCode : uint16_t {
        Escape_Pressed = 0x01,
        Number1_Pressed = 0x02,
        Number2_Pressed = 0x03,
        Number3_Pressed = 0x04,
        Number4_Pressed = 0x05,
        Number5_Pressed = 0x06,
        Number6_Pressed = 0x07,
        Number7_Pressed = 0x08,
        Number8_Pressed = 0x09,
        Number9_Pressed = 0x0A,
        Number0_Pressed = 0x0B,
        Minus_Pressed = 0x0C,
        EqualSign_Pressed = 0x0D,
        Backspace_Pressed = 0xE0,
        Tab_Pressed = 0x0F,
        Q_Pressed = 0x10,
        W_Pressed = 0x11,
        E_Pressed = 0x12,
        R_Pressed = 0x13,
        T_Pressed = 0x14,
        Y_Pressed = 0x15,
        U_Pressed = 0x16,
        I_Pressed = 0x17,
        O_Pressed = 0x18,
        P_Pressed = 0x19,
        LeftBracket_Pressed = 0x1A,
        RightBracket_Pressed = 0x1B,
        Enter_Pressed = 0x1C,
        Left_Control_Pressed = 0x1D,
        A_Pressed = 0x1E,
        S_Pressed = 0x1F,
        D_Pressed = 0x20,
        F_Pressed = 0x21,
        G_Pressed = 0x22,
        H_Pressed = 0x23,
        J_Pressed = 0x24,
        K_Pressed = 0x25,
        L_Pressed = 0x26,
        Semicolon_Pressed = 0x27,
        Quote_Pressed = 0x28,
        BackTick_Pressed = 0x29,
        Left_Shift_Pressed = 0x2A,
        Backslash_Pressed = 0x2B,
        Z_Pressed = 0x2C,
        X_Pressed = 0x2D,
        C_Pressed = 0x2E,
        V_Pressed = 0x2F,
        B_Pressed = 0x30,
        N_Pressed = 0x31,
        M_Pressed = 0x32,
        Comma_Pressed = 0x33,
        Dot_Pressed = 0x34,
        Slash_Pressed = 0x35,
        Right_Shift_Pressed = 0x36,
        Keypad_Asterisk_Pressed = 0x37,
        Left_Alt_Pressed = 0x38,
        Space_Pressed = 0x39,
        CapsLock_Pressed = 0x3A,
        F1_Pressed = 0x3B,
        F2_Pressed = 0x3C,
        F3_Pressed = 0x3D,
        F4_Pressed = 0x3E,
        F5_Pressed = 0x3F,
        F6_Pressed = 0x40,
        F7_Pressed = 0x41,
        F8_Pressed = 0x42,
        F9_Pressed = 0x43,
        F10_Pressed = 0x44,
        NumberLock_Pressed = 0x45,
        ScrollLock_Pressed = 0x46,
        Keypad_7_Pressed = 0x47,
        Keypad_8_Pressed = 0x48,
        Keypad_9_Pressed = 0x49,
        Keypad_Minus_Pressed = 0x4A,
        Keypad_4_Pressed = 0x4B,
        Keypad_5_Pressed = 0x4C,
        Keypad_6_Pressed = 0x4D,
        Keypad_Plus_Pressed = 0x4E,
        Keypad_1_Pressed = 0x4F,
        Keypad_2_Pressed = 0x50,
        Keypad_3_Pressed = 0x51,
        Keypad_0_Pressed = 0x52,
        Keypad_Dot_Pressed = 0x53,
        F11_Pressed = 0x57,
        F12_Pressed = 0x58,
        Escape_Released = 0x81,
        Number1_Released = 0x82,
        Number2_Released = 0x83,
        Number3_Released = 0x84,
        Number4_Released = 0x85,
        Number5_Released = 0x86,
        Number6_Released = 0x87,
        Number7_Released = 0x88,
        Number8_Released = 0x89,
        Number9_Released = 0x8A,
        Number0_Released = 0x8B,
        Minus_Released = 0x8C,
        EqualSign_Released = 0x8D,
        Backspace_Released = 0x8E,
        Tab_Released = 0x8F,
        Q_Released = 0x90,
        W_Released = 0x91,
        E_Released = 0x92,
        R_Released = 0x93,
        T_Released = 0x94,
        Y_Released = 0x95,
        U_Released = 0x96,
        I_Released = 0x97,
        O_Released = 0x98,
        P_Released = 0x99,
        LeftBracket_Released = 0x9A,
        RightBracket_Released = 0x9B,
        Enter_Released = 0x9C,
        Left_Control_Released = 0x9D,
        A_Released = 0x9E,
        S_Released = 0x9F,
        D_Released = 0xA0,
        F_Released = 0xA1,
        G_Released = 0xA2,
        H_Released = 0xA3,
        J_Released = 0xA4,
        K_Released = 0xA5,
        L_Released = 0xA6,
        Semicolon_Released = 0xA7,
        Quote_Released = 0xA8,
        BackTick_Released = 0xA9,
        Left_Shift_Released = 0xAA,
        Backslash_Released = 0xAB,
        Z_Released = 0xAC,
        X_Released = 0xAD,
        C_Released = 0xAE,
        V_Released = 0xAF,
        B_Released = 0xB0,
        N_Released = 0xB1,
        M_Released = 0xB2,
        Comma_Released = 0xB3,
        Dot_Released = 0xB4,
        Slash_Released = 0xB5,
        Right_Shift_Released = 0xB6,
        Keypad_Asterisk_Released = 0xB7,
        Left_Alt_Released = 0xB8,
        Space_Released = 0xB9,
        CapsLock_Released = 0xBA,
        F1_Released = 0xBB,
        F2_Released = 0xBC,
        F3_Released = 0xBD,
        F4_Released = 0xBE,
        F5_Released = 0xBF,
        F6_Released = 0xC0,
        F7_Released = 0xC1,
        F8_Released = 0xC2,
        F9_Released = 0xC3,
        F10_Released = 0xC4,
        NumberLock_Released = 0xC5,
        ScrollLock_Released = 0xC6,
        Keypad_7_Released = 0xC7,
        Keypad_8_Released = 0xC8,
        Keypad_9_Released = 0xC9,
        Keypad_Minus_Released = 0xCA,
        Keypad_4_Released = 0xCB,
        Keypad_5_Released = 0xCC,
        Keypad_6_Released = 0xCD,
        Keypad_Plus_Released = 0xCE,
        Keypad_1_Released = 0xCF,
        Keypad_2_Released = 0xD0,
        Keypad_3_Released = 0xD1,
        Keypad_0_Released = 0xD2,
        Keypad_Dot_Released = 0xD3,
        F11_Released = 0xD7,
        F12_Released = 0xD8,
        Multimedia_PreviousTrack_Pressed = 0xE010,
        Multimedia_NextTrack_Pressed = 0xE019,
        Keypad_Enter_Pressed = 0xE01C,
        Right_Control_Pressed = 0xE01D,
        Multimedia_Mute_Pressed = 0xE020,
        Multimedia_Calculator_Pressed = 0xE021,
        Multimedia_Play_Pressed = 0xE022,
        Multimedia_Stop_Pressed = 0xE024,
        Multimedia_VolumeDown_Pressed = 0xE02E,
        Multimedia_VolumeUp_Pressed = 0xE030,
        Multimedia_WWW_Home_Pressed = 0xE032,
        Keypad_Slash_Pressed = 0xE035,
        Right_Alt_Pressed = 0xE038,
        Home_Pressed = 0xE047,
        CursorUp_Pressed = 0xE048,
        PageUp_Pressed = 0xE049,
        CursorLeft_Pressed = 0xE04B,
        CursorRight_Pressed = 0xE04D,
        End_Pressed = 0xE04F,
        CursorDown_Pressed = 0xE050,
        PageDown_Pressed = 0xE051,
        Insert_Pressed = 0xE052,
        Delete_Pressed = 0xE053,
        Left_GUI_Pressed = 0xE05B,
        Right_GUI_Pressed = 0xE05C,
        Apps_Pressed = 0xE05D,
        ACPI_Power_Pressed = 0xE05E,
        ACPI_Sleep_Pressed = 0xE05F,
        ACPI_Wake_Pressed = 0xE063,
        Multimedia_WWW_Search_Pressed = 0xE065,
        Multimedia_WWW_Favorites_Pressed = 0xE066,
        Multimedia_WWW_Refresh_Pressed = 0xE067,
        Multimedia_WWW_Stop_Pressed = 0xE068,
        Multimedia_WWW_Forward_Pressed = 0xE069,
        Multimedia_WWW_Back_Pressed = 0xE06A,
        Multimedia_MyComputer_Pressed = 0xE06B,
        Multimedia_EMail_Pressed = 0xE06C,
        Multimedia_MediaSelect_Pressed = 0xE06D,
        Multimedia_PreviousTrack_Released = 0xE090,
        Multimedia_NextTrack_Released = 0xE099,
        Keypad_Enter_Released = 0xE09C,
        Right_Control_Released = 0xE09D,
        Multimedia_Mute_Released = 0xE0A0,
        Multimedia_Calculator_Released = 0xE0A1,
        Multimedia_Play_Released = 0xE0A2,
        Multimedia_Stop_Released = 0xE0A4,
        Multimedia_VolumeDown_Released = 0xE0AE,
        Multimedia_VolumeUp_Released = 0xE0B0,
        Multimedia_WWW_Home_Released = 0xE0B2,
        Keypad_Slash_Released = 0xE0B5,
        Right_Alt_Released = 0xE0B8,
        Home_Released = 0xE0C7,
        CursorUp_Released = 0xE0C8,
        PageUp_Released = 0xE0C9,
        CursorLeft_Released = 0xE0CB,
        CursorRight_Released = 0xE0CD,
        End_Released = 0xE0CF,
        CursorDown_Released = 0xE0D0,
        PageDown_Released = 0xE0D1,
        Insert_Released = 0xE0D2,
        Delete_Released = 0xE0D3,
        Left_GUI_Released = 0xE0DB,
        Right_GUI_Released = 0xE0DC,
        Apps_Released = 0xE0DD,
        ACPI_Power_Released = 0xE0DE,
        ACPI_Sleep_Released = 0xE0DF,
        ACPI_Wake_Released = 0xE0E3,
        Multimedia_WWW_Search_Released = 0xE0E5,
        Multimedia_WWW_Favorites_Released = 0xE0E6,
        Multimedia_WWW_Refresh_Released = 0xE0E7,
        Multimedia_WWW_Stop_Released = 0xE0E8,
        Multimedia_WWW_Forward_Released = 0xE0E9,
        Multimedia_WWW_Back_Released = 0xE0EA,
        Multimedia_My_Computer_Released = 0xE0EB,
        Multimedia_EMail_Released = 0xE0EC,
        Multimedia_Media_Select_Released = 0xE0ED,
        PrintScreen_Pressed = 0xFFFD,
        PrintScreen_Release = 0xFFFE,
        Pause_Pressed = 0xFFFF,
    };

    /**
     * Enables the A20 bit in the PS/2 controller.
     */
    void EnableA20();

    /**
     * Initializes the PS/2 keyboard.
     *
     * @return whether or not the initialization was successful.
     */
    bool InitializeKeyboard();

    /**
     * Tries to read a scan code from the PS/2 keyboard.
     *
     * @param code output buffer, will be set only if the returned value is true
     *
     * @return whether or not a full scan code was available
     */
    bool TryReadScanCode(ScanCode& code);
}  // namespace FunnyOS::HW::PS2

#endif  // FUNNYOS_MISC_HARDWARE_HEADERS_FUNNYOS_HARDWARE_PS2_HPP
