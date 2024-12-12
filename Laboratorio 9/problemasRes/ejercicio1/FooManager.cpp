#include "FooManager.h"
#include <iostream>

// Inicialización de la instancia estática
FooManager* FooManager::m_Inst = nullptr;

// Constructor
FooManager::FooManager() : SampleData(100) {}

// Destructor
FooManager::~FooManager() {}

// Crear la instancia
void FooManager::Create()
{
    if (m_Inst == nullptr)
    {
        m_Inst = new FooManager();
    }
}

// Obtener la instancia
FooManager* FooManager::GetInst()
{
    return m_Inst;
}

// Liberar la instancia
void FooManager::Destroy()
{
    delete m_Inst;
    m_Inst = nullptr;
}

// Obtener el dato de muestra
int FooManager::GetSampleData()
{
    return SampleData;
}
