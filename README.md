# 🎮 *BomberMan FanGame* 🎮

El clásico renace con nuevas reglas... y más explosiones.

![Icono de la Imagen](URL-de-la-imagen)

---

## 🌌 *Sinopsis del Juego*

Sumérgete en un universo alternativo donde las bombas no solo destruyen, también construyen el camino hacia la victoria.
*BomberMan FanGame* es un videojuego creado con *Unreal Engine 5.5.3* que combina acción, estrategia y exploración.
Controla a un personaje icónico mientras atraviesas escenarios misteriosos, enfrentas enemigos impredecibles y colocas bombas como única arma y aliada.

---

## 🔍 *Resumen del Proyecto*

🎮 *Tipo de juego:* Aventura - Acción táctica
🏛️ *Universidad:* Universidad San Francisco Xavier de Chuquisaca 
🏫 *Facultad:* Tecnología
📚 *Materia:* Programación Avanzada (SIS-457)
👨‍🏫 *Docente guía:* Ing. Carlos Walter Pacheco Lora
📆 *Semestre:* 1/2025

---

## 👨‍💻 *Equipo de Desarrollo*

* 💣 *Alex Josué Calatayud Mamani*
* 💣 *Luis Fernando Quispe Sullca*

---

## 🧩 *Componentes y Módulos Clave*

| Módulo                      | Descripción                                                      |
| --------------------------- | ---------------------------------------------------------------- |
| 🧨 *Sistema de Bombas*    | Explosiones dinámicas con lógica de daño y física realista.      |
| 🤖 *IA de Enemigos*       | Patrullaje, detección, persecución.                     |
| 🧪 *Power-Ups*            | Mejora de habilidades: velocidad, mayor rango de daño con explosiones.     |
| 🏴‍☠️ *Enemigo Final*     | Jefes con inteligencia adaptativa y patrones únicos.             |
| ⚙️ *Trampas & Centinelas* | Elementos interactivos como sensores y proyectiles inteligentes. |
---

## 🧠 *Patrones de Diseño Utilizados*

📦 *Abstract Factory*

> Generación flexible de enemigos según familia y tipo.
```mermaid
classDiagram
    %% Interfaz Abstract Factory
    class AbstractFactory {
        <<interface>>
        +CrearEnemigo() Enemigo
        +CrearBloque() Bloque
        +CrearDecoraciones() Decoracion
    }

    %% Fábricas concretas
    class Fabrica1 {
        +CrearEnemigo() Enemigo1
        +CrearBloque() Bloque1
        +CrearDecoraciones() Decoracion1
    }

    class Fabrica2 {
        +CrearEnemigo() Enemigo2
        +CrearBloque() Bloque2
        +CrearDecoraciones() Decoracion2
    }

    %% Productos abstractos
    class Enemigo {
        <<abstract>>
    }
    class Bloque {
        <<abstract>>
    }
    class Decoracion {
        <<abstract>>
    }

    %% Productos concretos
    class Enemigo1
    class Bloque1
    class Decoracion1
    class Enemigo2
    class Bloque2
    class Decoracion2

    %% Cliente
    class Escenario {
        +Escenario(f: AbstractFactory)
        +OperacionesCrear()
    }

    %% Relaciones (usar --|> para herencia y --> para uso)
    AbstractFactory <|-- Fabrica1
    AbstractFactory <|-- Fabrica2

    Enemigo <|-- Enemigo1
    Enemigo <|-- Enemigo2
    Bloque <|-- Bloque1
    Bloque <|-- Bloque2
    Decoracion <|-- Decoracion1
    Decoracion <|-- Decoracion2

    Fabrica1 ..> Enemigo1 : «crea»
    Fabrica1 ..> Bloque1 : «crea»
    Fabrica1 ..> Decoracion1 : «crea»
    Fabrica2 ..> Enemigo2 : «crea»
    Fabrica2 ..> Bloque2 : «crea»
    Fabrica2 ..> Decoracion2 : «crea»

    Escenario --> AbstractFactory : usa
```

🏗️ *Builder*



> Construcción progresiva de niveles y obstáculos.
```mermaid
classDiagram
    %% Interfaz Builder (versión compatible)
    class Builder {
        <<interface>>
        +Reiniciar()
        +builderBloques()
        +builderEnemigos()
        +builderPowerUp()
    }

    %% Director
    class Director {
        -builder: Builder
        +Director(builder)
        +CambiarBuilder(builder)
        +Crear(TipoBuilder)
    }

    %% Builders concretos
    class BuilderCiudad {
        -Resultado: MapaCiudad
        +Reiniciar()
        +builderBloques()
        +builderEnemigos()
        +builderPowerUp()
        +GetResultado()$ MapaCiudad
    }

    class BuilderDesierto {
        -Resultado: MapaDesierto
        +Reiniciar()
        +builderBloques()
        +builderEnemigos()
        +builderPowerUp()
        +GetResultado()$ MapaDesierto
    }

    class BuilderDeOtrosMundos {
        -Resultado: MapaDeOtrosMundos
        +Reiniciar()
        +builderBloques()
        +builderEnemigos()
        +builderPowerUp()
        +GetResultado()$ MapasDeOtrosMundos
    }

    %% Productos
    class MapaCiudad
    class MapaDesierto
    class MapaDeOtrosMundos

    %% Relaciones
    Builder <|-- BuilderCiudad
    Builder <|-- BuilderDesierto
    Builder <|-- BuilderDeOtrosMundos

    Director *-- Builder

    BuilderCiudad --> MapaCiudad
    BuilderDesierto --> MapaDesierto
    BuilderDeOtrosMundos --> MapaDeOtrosMundos
```
---
🎭 *Facade*

> Control centralizado del sistema de jugador y entorno para el nivel de dificultad.
```mermaid
classDiagram
    %% Widget (parte superior)
    class Widget {
        +OnDificultadCambiada()
    }

    %% GestorFacade (centro, conecta niveles y widget)
    class GestorFacade {
        -configuracion: IConfiguracion*
        +SetConfiguracion(IConfiguracion*)
        +EjecutarDificultad()
        +ActualizarWidget()
    }

    %% Niveles (conectados a GestorFacade)
    class NivelFacil {
        +VelocidadEnemigos() 0.5
        +ConfiguracionVida() 100
        +ConfiguracionCantidadEnemigos() 10
    }
    class NivelMedio {
        +VelocidadEnemigos() 1.0
        +ConfiguracionVida() 70
        +ConfiguracionCantidadEnemigos() 20
    }
    class NivelDificil {
        +VelocidadEnemigos() 2.0
        +ConfiguracionVida() 50
        +ConfiguracionCantidadEnemigos() 30
    }

    %% Interfaz (abajo, implementada por niveles)
    class IConfiguracion {
        <<interface>>
        +VelocidadEnemigos() float
        +ConfiguracionVida() int
        +ConfiguracionCantidadEnemigos() int
    }

    %% RELACIONES:
    NivelFacil --|> IConfiguracion
    NivelMedio --|> IConfiguracion
    NivelDificil --|> IConfiguracion

    GestorFacade "1" *-- "1" NivelFacil : "Usa (puntero )"
    GestorFacade "1" *-- "1" NivelMedio : "Usa (puntero)"
    GestorFacade "1" *-- "1" NivelDificil : "Usa (puntero)"
    GestorFacade --> Widget : "Notifica"
```
---
⚔️ *Strategy*

> Algoritmos de combate variables según distancia y contexto.
```mermaid
classDiagram
    %% Contexto
    class Contexto {
        -Strategy estrategia
        +SetStrategy()
        +EjecutarUnaEstrategia()
    }

    %% Interfaz Strategy (versión compatible)
    class Strategy {
        <<interface>>
        +Ejecutar()
    }

    %% Clase Enemigos
    class Enemigos {
        +EjecutarPersecucion()
        +EjecutarPatrullaje()
    }

    %% Estrategias concretas
    class EstrategiaPerseguir {
        +Ejecutar()
    }

    class EstrategiaPatrullar {
        +Ejecutar()
    }

    %% Relaciones
    Contexto o--> Strategy
    Strategy <|-- EstrategiaPerseguir
    Strategy <|-- EstrategiaPatrullar
    Enemigos --> EstrategiaPerseguir : "Usa para Perseguir"
    Enemigos --> EstrategiaPatrullar : "Usa para Patrullar"
```
----
🧿 *Observer*

> Activación de eventos de trampas al interactuar con el entorno.

```mermaid
classDiagram
    %% Interfaz Observer
    class Observer {
        <<interface>>
        -suscriptor
        +TrampaActivada()
    }

    %% Clase Centinela (implementa Observer)
    class Centinela {
        -suscriptor
        +Atacar()
        +TrampaActivada()
    }

    %% Relaciones (implementación múltiple)
    Observer <|.. Centinela : "implementa"
    Observer <|.. Centinela : "implementa" 
    Observer <|.. Centinela : "implementa"
    Observer <|.. Centinela : "implementa"
    Observer <|.. Centinela : "implementa"
```
---

## 🌄 *Vista Previa del Proyecto*

Incluye:

* 📑 Documentación técnica detallada
* 📊 Diagramas UML
* 🧠 Lógica y diseño de IA enemiga
* 🔄 Sistema de colisiones y físicas
* 📸 Capturas y escenas jugables
* 🧾 Código fuente completo en GitHub

---

## 🌐 *Próximamente Disponible*

📥 *Enlace al ejecutable*
(En fase de pruebas finales y empaquetado.)

---

💥 ¡Piensa rápido, coloca bien tus bombas y domina el laberinto! 💥

Explota con nosotros el universo de *BomberMan FanGame* y revive la esencia de un clásico desde una nueva dimensión.
