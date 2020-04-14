#ifndef FUNNYOS_STDLIB_HEADERS_FUNNYOS_STDLIB_MEMORY_HPP
#define FUNNYOS_STDLIB_HEADERS_FUNNYOS_STDLIB_MEMORY_HPP

#include "IntegerTypes.hpp"

namespace FunnyOS::Stdlib::Memory {

    /**
     * A pointer to memory that also holds the size.
     *
     * @tparam T pointer type
     */
    template <typename T>
    struct SizedBuffer {
        /**
         * Pointer to memory
         */
        T* Data;

        /**
         * Size of the memory in bytes.
         */
        size_t Size;

        /**
         * Checks if the buffer is valid (it's Data is not nullptr)
         *
         * @return whether or not the buffer is valid
         */
        inline bool IsValid();

        /**
         * Gets the N'th element in the buffer.
         * This function does NOT check the boundary.
         *
         * @param index index of element to get
         * @return pointer to that element
         */
        inline T* operator[](size_t index);

        /**
         * Gets the N'th element in the buffer.
         * This function does NOT check the boundary.
         *
         * @param index index of element to get
         * @return pointer to that element
         */
        inline T const* operator[](size_t index) const;
    };

    /**
     * Copies [destination.Size] bytes from [source] to [destination.Data]
     */
    template <typename Type>
    inline void Copy(SizedBuffer<Type>& destination, const Type* source);

    /**
     * Copies [size] bytes from [source] to [destination]
     */
    template <typename Type>
    inline void Copy(Type* destination, const Type* source, size_t size);

    /**
     * Sets [destination.Size] at [destination.Data] to [byte]
     */
    template <typename Type>
    inline void Set(SizedBuffer<Type>& destination, Type byte);

    /**
     * Fills the whole [destination] with repeating patterns of [pattern]
     */
    template <typename Type>
    inline void Fill(SizedBuffer<Type>& destination, const SizedBuffer<Type>& pattern);

    /**
     * Allocates N bytes of memory on the heap.
     *
     * @param[in] size number of bytes to allocate may be zero.
     *
     * @return allocated memory or nullptr if there is not enough mermory
     */
    [[nodiscard]] void* Allocate(size_t size);

    /**
     * Allocates N bytes of aligned memory on the heap.
     *
     * @param[in] size number of bytes to allocate may be zero.
     * @param[in] alignment memory alignment
     *
     * @return allocated memory or nullptr if there is not enough memory.
     *         Returned value is divisible by alignment if the allocator supports alignment.
     */
    [[nodiscard]] void* AllocateAligned(size_t size, size_t alignment);

    /**
     * Allocates a SizedBuffer<T> of the heap.
     * If there is not enough memory the returned buffer's Size and Data will be 0 and nullptr respectively.
     *
     * @tparam T type of the newly allocated buffer
     *
     * @param[in] size size of the memory to allocate, the actual allocated number of bytes will be this size multiplied
     * by sizeof(T)
     *
     * @return newly allocated buffer.
     */
    template <typename T>
    [[nodiscard]] inline SizedBuffer<T> AllocateBuffer(size_t size);

    /**
     * Reallocates memory in a buffer.
     * The contents of the buffer will be retained or shrunk if the new size is smaller then the old one
     *
     * If there is not enough memory for reallocation the buffer will be freed. And buffer.Data will be set to nullptr.
     *
     * @tparam T type of the buffer
     * @param[in] buffer buffer to reallocate
     * @param[in] size new size to allocate
     */
    template <typename T>
    inline void ReallocateBuffer(SizedBuffer<T>& buffer, size_t size);

    /**
     * Frees a buffer and sets its data to nullptr.
     *
     * @tparam T type of the buffer
     * @param buffer buffer to free
     */
    template <typename T>
    inline void FreeBuffer(SizedBuffer<T>& buffer);

    /**
     * Allocates N bytes of memory on the heap and initialize it with zeros.
     *
     * @param[in] size number of bytes to allocate may be zero.
     *
     * @return zero-initialized allocated memory or nullptr if there is not enough memory.
     */
    [[nodiscard]] void* AllocateInitialized(size_t size);

    /**
     * Reallocates the given memory previously allocated via any Allocate* or Reallocate* methods.
     * The contents of the newly allocated memory will be copied from the old memory.
     *
     * If the returned value != nullptr then the old memory will be freed as if Free(data) was called.
     *
     * @param[in, out] ptr memory to reallocate, is freed when returned value != nullptr
     * @param[in] size size of the memory block.
     * @return the newly allocated chunk or nullptr if not enough memory.
     */
    [[nodiscard]] void* Reallocate(void* data, size_t size);

    /**
     * Frees a chunk of memory previously allocated via any Allocate* or Reallocate* methods.
     * Any other parameter will cause an undefined behaviour.
     *
     * @param[in, out] ptr memory to free
     */
    void Free(void* data);

}  // namespace FunnyOS::Stdlib::Memory

#include "Memory.tcc"
#endif  // FUNNYOS_STDLIB_HEADERS_FUNNYOS_STDLIB_MEMORY_HPP