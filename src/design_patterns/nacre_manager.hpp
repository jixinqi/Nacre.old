#ifndef _NACRE_MANAGER_HPP_
#define _NACRE_MANAGER_HPP_

namespace nacre
{
    template<
        typename Key,
        typename Value
    >
    class key_value_type
    {
    public:
        template<
            typename Key_T = Key,
            typename Value_T = Value
        >
        key_value_type(Key_T && _key, Value_T && _value)
        : key{ _key }
        , value{ _value }
        {
        }

        Key   key;
        Value value;
    };

    template<
        typename Key,
        typename Value,
        std::enable_if_t<
            std::has_virtual_destructor_v<Value>,
            int
        > = 0
    >
    class object : public Value
    {
    public:
        object() = delete;

        template<
            typename Key_T = Key
        >
        object(Key_T && _key)
        : key{ _key }
        {
        }

        template<
            typename Key_T = Key,
            typename Value_T = Value
        >
        object(Key_T && _key, Value_T && _value)
        : Value{ _value }
        , key{ _key }
        {
        }

        const Key key;

    protected:
    private:
    };

    template<
        typename Key,
        typename Value
    >
    class manager
    {
    public:
        manager() = default;

        manager(std::initializer_list<key_value_type<Key, Value>> l)
        {
            for (const auto& item : l)
            {
                add(item.key, item.value);
            }
        }

        virtual ~manager() = default;

        template<
            typename Key_T = Key
        >
        const bool is_exists(Key_T && _key) const
        {
            return data_.find(_key) != data_.end();
        }

        template<
            typename Key_T = Key
        >
        object<Key, Value>& add(Key_T && _key)
        {
            assert(!is_exists(_key));
            return add_no_exception(_key);
        }

        template<
            typename Key_T = Key,
            typename Value_T = Value
        >
        object<Key, Value>& add(Key_T && _key, Value_T && _value)
        {
            assert(!is_exists(_key));
            return add_no_exception(_key, _value);
        }

        template<
            typename Key_T = Key
        >
        object<Key, Value>& get(Key_T && _key)
        {
            assert(is_exists(_key));
            return get_no_exception(_key);
        }

        template<
            typename Key_T = Key
        >
        void del(Key_T && _key)
        {
            assert(is_exists(_key));
            data_.erase(_key);
        }

    protected:
    private:
        template<typename Key_T = Key>
        object<Key, Value>& add_no_exception(Key_T && _key)
        {
            data_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(_key),
                std::forward_as_tuple(_key)
            );
            return data_.at(_key);
        }

        template<
            typename Key_T = Key,
            typename Value_T = Value
        >
        object<Key, Value>& add_no_exception(Key_T && _key, Value_T && _value)
        {
            data_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(_key),
                std::forward_as_tuple(_key, _value)
            );
            return data_.at(_key);
        }

        template<
            typename Key_T = Key
        >
        object<Key, Value>& get_no_exception(Key_T && _key)
        {
            return data_.at(_key);
        }

        std::map<Key, object<Key, Value>> data_;
    };
}

#endif
