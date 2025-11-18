#include "pch.h" // <-- IMPORTANTE: Esta debe ser SIEMPRE la primera línea
#include "CppUnitTest.h"

// Incluimos el archivo de tu librería para ver si la conexión funciona
// (Si te marca error aquí, es que falta el paso de "Directorios de inclusión adicionales")
#include <models/Paciente.hpp> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Pruebas
{
	TEST_CLASS(ClaseDePruebas)
	{
	public:

		TEST_METHOD(PruebaDeConexion)
		{
			// 1. Intentamos crear un Paciente usando tu estructura
			Modelo::Paciente miPaciente;
			miPaciente.id = 123;
			miPaciente.nombre = "Prueba";

			// 2. El "Assert" es el juez. Si los valores coinciden, la prueba pasa (verde).
			Assert::AreEqual(123, miPaciente.id);
		}
	};
}