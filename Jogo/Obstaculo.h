#pragma once
namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo
		{
		protected:
			bool Danificavel;
			bool Perigoso;
		public:
			Obstaculo();
			~Obstaculo();
		};
	}
}
