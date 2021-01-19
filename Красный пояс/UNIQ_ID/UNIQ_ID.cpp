#define UNIQ_ID_IMPL_2(lineno) _a_local_variable_##lineno
#define UNIQ_ID_IMPL(lineno) UNIQ_ID_IMPL_2(lineno)
#define UNIQ_ID UNIQ_ID_IMPL(__LINE__)

int main()
{
    int UNIQ_ID = 5;
    float UNIQ_ID = 6.;
}
