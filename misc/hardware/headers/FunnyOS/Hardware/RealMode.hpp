#ifndef FUNNYOS_MISC_HARDWARE_HEADERS_FUNNYOS_HARDWARE_REALMODE_HPP
#define FUNNYOS_MISC_HARDWARE_HEADERS_FUNNYOS_HARDWARE_REALMODE_HPP

#include <FunnyOS/Stdlib/Compiler.hpp>
#include <FunnyOS/Stdlib/IntegerTypes.hpp>
#include <FunnyOS/Stdlib/Memory.hpp>
#include <FunnyOS/Stdlib/System.hpp>

namespace FunnyOS::HW {
    using namespace Stdlib;

    /**
     * Represents a 16-bit register.
     */
    union Register16 {
        struct Parts {
            uint8_t Low;
            uint8_t High;
        } F_DONT_ALIGN;

        /**
         * 16-bit value of the register.
         */
        uint16_t Value16;

        /**
         * Structure holding low and high bytes of the register.
         */
        Parts Value8;
    } F_DONT_ALIGN;

    /**
     * Represents all registers that can be used to make a real mode interrupt.
     */
    struct Registers16 {
        Register16 AX = {0};
        Register16 CX = {0};
        Register16 DX = {0};
        Register16 BX = {0};
        Register16 SI = {0};
        Register16 DI = {0};
        Register16 ES = {0};
        Register16 FS = {0};
        Register16 GS = {0};
        Register16 FLAGS = {0};
    } F_DONT_ALIGN;

    /**
     * Information required for the real mode interrupt function to work.
     */
    struct GDTInfo {
        /**
         * Selector for the GDT entry containing a entry for 32-bit code descriptor.
         */
        uint16_t SelectorCode32;

        /**
         * Selector for the GDT entry containing a entry for 32-bit data descriptor.
         */
        uint16_t SelectorData32;

        /**
         * Selector for the GDT entry containing a entry for 16-bit code descriptor.
         */
        uint16_t SelectorCode16;

        /**
         * Selector for the GDT entry containing a entry for 16-bit data descriptor.
         */
        uint16_t SelectorData16;
    } F_DONT_ALIGN;

    /**
     * Updates up the internal GDTInfo structure to support the real mode interrupt function.
     * It assumes a flat memory model.
     *
     * @param gdtInfo GDTInfo structure to be used
     */
    void SetupRealModeInterrupts(GDTInfo gdtInfo);

    /**
     * Gets a buffer that is guaranteed to be fully located below the 1 MB mark and thus fully accessible in real mode.
     * Size of the buffer is implementation defined.
     *
     * @return real mode buffer
     */
    Memory::SizedBuffer<uint8_t>& GetRealModeBuffer();

    /**
     * Gets the address of real mode buffer (see GetRealModeBuffer()) in a segment:offset form.
     *
     * @param[out] segment segment part of the buffer's address
     * @param[out] offset offset part of the buffer's address
     */
    void GetRealModeBufferAddress(uint16_t& segment, uint16_t& offset);

    /**
     * Executes a real mode interrupt.
     *
     * @param interrupt interrupt number.
     *
     * @param[in,out] registers value of the 16-bit registers to hold parameters and return values for the interrupt.
     */
    void RealModeInt(uint8_t interrupt, Registers16& registers);

}  // namespace FunnyOS::HW

#endif  // FUNNYOS_MISC_HARDWARE_HEADERS_FUNNYOS_HARDWARE_REALMODE_HPP
