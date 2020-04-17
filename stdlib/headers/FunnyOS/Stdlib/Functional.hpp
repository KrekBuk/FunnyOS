#ifndef FUNNYOS_STDLIB_HEADERS_FUNNYOS_STDLIB_FUNCTIONAL_HPP
#define FUNNYOS_STDLIB_HEADERS_FUNNYOS_STDLIB_FUNCTIONAL_HPP

// Iterator support
#define HAS_STANDARD_ITERATORS               \
    using iterator = Iterator;               \
    using const_iterator = ConstIterator;    \
    iterator begin() {                       \
        return this->Begin();                \
    }                                        \
    iterator end() {                         \
        return this->End();                  \
    }                                        \
    constexpr const_iterator begin() const { \
        return this->Begin();                \
    }                                        \
    constexpr const_iterator end() const {   \
        return this->End();                  \
    }

#include "System.hpp"
#include "Utility.hpp"
#include "InitializerList.tcc"

namespace FunnyOS::Stdlib {

    /**
     * An object of type initializer_list<T> is a lightweight proxy object that provides access to an array of objects
     * of type const T.
     */
    template <typename T>
    using InitializerList = std::initializer_list<T>;

    /**
     * Thrown when an empty optional is accessed improperly.
     */
    F_TRIVIAL_EXCEPTION(EmptyOptionalException, "FunnyOS::Stdlib::EmptyOptionalException");

    /**
     * Represents a type that can be passed to an optional constructor to create an empty optional.
     */
    struct NullOptionalType {
        constexpr static const NullOptionalType* Value = static_cast<const NullOptionalType*>(nullptr);
    };

    /**
     * Represents a container that can have a value or be empty.
     *
     * @tparam T
     */
    template <typename T>
    class Optional {
       public:
        TRIVIALLY_COPYABLE(Optional);
        TRIVIALLY_MOVEABLE(Optional);

        /**
         * Constructs an empty optional.
         */
        inline Optional() noexcept;

        /**
         * Destructs the optional
         */
        ~Optional() = default;

        /**
         * Constructs an empty optional
         */
        inline explicit Optional(const NullOptionalType* /*unused*/) noexcept;

        /**
         * Constructs an optional and initializes it using the provided value.
         */
        template <typename U = T, typename = EnableIf<!IsSame<U, NullOptionalType>>>
        inline Optional(U&& value);

        /**
         * Returns whether or not this optional has a value
         * @return whether or not this optional has a value
         */
        [[nodiscard]] inline bool HasValue() const noexcept;

        /**
         * Returns the value of this optional or throws EmptyOptionalException if te optional is not initialized.
         *
         * @return the value of this optional
         */
        [[nodiscard]] inline T& GetValue();

        /**
         * Returns the value of this optional or throws EmptyOptionalException if te optional is not initialized.
         *
         * @return the value of this optional
         */
        [[nodiscard]] inline const T& GetValue() const;

        /**
         * Returns the value of this optional or [defaultValue] if te optional is not initialized.
         *
         * @param defaultValue default value
         * @return the value of this optional or [defaultValue]
         */
        inline T GetValueOrDefault(T&& defaultValue) noexcept;

        /**
         * Returns the value of this optional or [defaultValue] if te optional is not initialized.
         *
         * @param defaultValue default value
         * @return the value of this optional or [defaultValue]
         */
        inline T GetValueOrDefault(T&& defaultValue) const noexcept;

        /**
         * Returns the value of this optional or throws EmptyOptionalException if te optional is not initialized.
         *
         * @return the value of this optional
         */
        [[nodiscard]] inline operator T&();

        /**
         * Returns the value of this optional or throws EmptyOptionalException if te optional is not initialized.
         *
         * @return the value of this optional
         */
        [[nodiscard]] inline operator const T&() const;

        /**
         * Returns the value of this optional or throws EmptyOptionalException if te optional is not initialized.
         *
         * @return the value of this optional
         */
        [[nodiscard]] inline operator bool();

        /**
         * Returns the value of this optional or throws EmptyOptionalException if te optional is not initialized.
         *
         * @return the value of this optional
         */
        [[nodiscard]] inline operator bool() const;

       private:
        template <typename T2, typename... Args>
        friend Optional<T2> MakeOptional(Args&&... args);

        template <typename... Args>
        inline explicit Optional(const InPlaceConstructor*, Args&&... args);

       private:
        Storage<T> m_storage;
    };

    /**
     * An empty optional of type T
     *
     * @tparam T type of the optional
     */
    template <typename T>
    [[nodiscard]] inline Optional<T> EmptyOptional() noexcept;

    /**
     * Makes an Optional with its value in-place.
     *
     * @tparam T type of the value
     * @tparam Args args to be passed to the constructor of T
     * @param args args to be passed to the constructor of T
     * @return the newly created Optional
     */
    template <typename T, typename... Args>
    [[nodiscard]] inline Optional<T> MakeOptional(Args&&... args);

}  // namespace FunnyOS::Stdlib

#include "Functional.tcc"
#endif  // FUNNYOS_STDLIB_HEADERS_FUNNYOS_STDLIB_FUNCTIONAL_HPP