#ifndef FOOMANAGER_H
#define FOOMANAGER_H

class FooManager
{
public:
    int GetSampleData();
    static void Create();
    static FooManager* GetInst();
    static void Destroy();

protected:
    FooManager();
    virtual ~FooManager();

private:
    int SampleData;
    static FooManager* m_Inst;
};

#endif
