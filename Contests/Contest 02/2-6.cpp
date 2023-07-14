#include <string>
#include <stdexcept>

class StringView {
private:
    const char* data_ = nullptr;
    size_t begin_ = 0;
    size_t count_ = 0;
public:
    // Конструкторы
    StringView(std::string& s, size_t begin = 0, size_t count = std::string::npos)
                : begin_(begin), count_(count) {
        if (begin_ > s.length() || count_ == 0)
            return;
        data_ = s.data() + begin_;
        count_ = std::min(s.length() - begin_, count_);
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos)
                : begin_(begin + sv.begin_), count_(count) {
        if (begin_ > sv.count_ || count_ == 0)
            return;
        data_ = sv.data_ + begin_;
        count_ = std::min(sv.count_ - begin_, count_);
    }

    // Доступ к элементам
    const char& operator[](size_t index) const
    {
        if (index >= count_)
            throw std::out_of_range("Index is out of range");
        return *(data_ + index);
    }

    // Получение размера представления
    size_t length() const { return count_; }
    size_t size() const { return count_; }

    // Получение подстроки
    std::string str(size_t begin = 0, size_t count = std::string::npos) const
    {
        if (begin > count_ || count == 0)
            return "";
        const char* start = data_ + begin;
        count = std::min(count_ - begin, count);
        return std::string(start, count);
    }

    // Запрещаем операцию присваивания
    StringView& operator = (const StringView&) = delete;
};