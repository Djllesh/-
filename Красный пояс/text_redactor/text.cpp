#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor() : cursor_pos(data.end()) {}
    void Left()
    { 
        if(cursor_pos != data.begin()) cursor_pos--; 
    }

    void Right()
    { 
        if(cursor_pos != data.end()) cursor_pos++;
    }

    void Insert(char token)
    {
        if (data.empty() || cursor_pos == data.end())
        {
            data.push_back(token);
        }
        else
        {
            data.insert(cursor_pos, token);
        }
    }

    void Cut(size_t tokens = 1)
    {
        buffer.clear();
        if (!data.empty() && cursor_pos != data.end())
        {
            auto temp_begin = cursor_pos;
            while (tokens && cursor_pos != data.end())
            {
                cursor_pos++;
                tokens--;
            }

            buffer.assign(temp_begin, cursor_pos);
            data.erase(temp_begin, cursor_pos);
        }
    }
     
    void Copy(size_t tokens = 1)
    {
        buffer.clear();
        if (!data.empty() && cursor_pos != data.end())
        {
            auto temp_begin = cursor_pos;
            while (tokens && cursor_pos != data.end())
            {
                cursor_pos++;
                tokens--;
            }

            buffer.assign(temp_begin, cursor_pos);
        }
    }

    void Paste()
    {
        if (!buffer.empty())
        {
            data.insert(cursor_pos, buffer.begin(), buffer.end());
        }
    }

    string GetText() const
    {
        string result;
        for (const auto& c : data)
        {
            result += c;
        }
        return result;
    }
private:
    list<char> data, buffer;
    list<char>::iterator cursor_pos;
};

void TypeText(Editor& editor, const string& text) {
    for (char c : text) {
        editor.Insert(c);
    }
}

void TestEditing() {
    {
        Editor editor;

        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        for (size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }
        editor.Cut(first_part_len);
        for (size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }
        TypeText(editor, ", ");
        editor.Paste();
        editor.Left();
        editor.Left();
        editor.Cut(3);

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");
        editor.Left();
        editor.Left();
        editor.Left();
        editor.Cut(1);
        editor.Right();
        editor.Paste();

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for (char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
    Editor editor;

    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestEditing);
    RUN_TEST(tr, TestReverse);
    RUN_TEST(tr, TestNoText);
    RUN_TEST(tr, TestEmptyBuffer);
    return 0;
}