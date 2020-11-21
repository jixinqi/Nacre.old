#ifndef _NACRE_MANAGER_HPP_
#define _NACRE_MANAGER_HPP_

namespace nacre
{
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

        template<typename Key_T>
        object(Key_T && _key)
        : key{ std::forward<Key>(_key) }
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
    class manager : private boost::noncopyable
    {
    public:
        manager() = default;
        virtual ~manager() = default;

        template<typename Key_T>
        bool is_exists(Key_T && _key)
        {
            return 
                data_.find(std::forward<Key>(_key))
                    != data_.end();
        }

        template<typename Key_T>
        object<Key, Value>& create(Key_T && _key)
        {
            assert(!is_exists(_key));
            data_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(_key),
                std::forward_as_tuple(_key)
            );
            return data_.at(_key);
        }

        object<Key, Value>& get(const Key& _key)
        {
            assert(is_exists(_key));
            return data_.at(_key);
        }

        void remove(const Key& _key)
        {
            assert(is_exists(_key));
            data_.erase(_key);
        }

    protected:
    private:
        std::map<Key, object<Key, Value>> data_;
    };
}

#endif
