# 🎮 *BomberMan FanGame* 🎮

El clásico juego renace con nuevas reglas... y más explosiones.

![Bomberman FanGame](https://github.com/Alex-JC-dot/BombermanUSFX/blob/main/Assets/Logo_BombermanFanGame.png)

<table style="width:100%;">
  <tr>
    <td style="width:30%; text-align:center; vertical-align:top;">
      <img src="https://github.com/Alex-JC-dot/BombermanUSFX/blob/main/Assets/Premiacion.png" alt="Premiación" style="height:220px; width:auto;">
    </td>
    <td style="width:70%; vertical-align:top; padding-left:30px;">
      <h2>🏆 Premiación</h2>
      <p style="font-size:16px;">
        Nos enorgullece compartir que este proyecto fue galardonado con el <strong>Primer lugar</strong> en la competencia.
      </p>
      <h2>📂 Categoría</h2>
      <p style="font-size:16px;">
        Este reconocimiento se obtuvo dentro de la categoría <strong>Exposición Libre</strong>, destacando por creatividad, presentación y desarrollo técnico.
      </p>
    </td>
  </tr>
</table>


## 🏆 Premiación

- **Primer lugar**

## 👨‍💻 Categoría

- **Exposición Libre**

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
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"><br><br>
<h1 align="center"><b>* 💣 Alex Josué Calatayud Mamani        Ing. SIS*  </b><img src="https://media.giphy.com/media/hvRJCLFzcasrR4ia7z/giphy.gif" width="35"></h1>

📞*Contactos*

<a href="https://x.com/Alex0Calatayud">
  <img src="https://img.shields.io/badge/X-%23000000.svg?style=for-the-badge&logo=X&logoColor=white">
</a>
<a href="mailto:alexcalatayud9@gmail.com">
  <img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Gmail" />
</a>
<a href="https://github.com/Alex-JC-dot">
  <img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">
</a>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"><br><br>
<h1 align="center"><b>* 💣 Luis Fernando Quispe Sullca         Ing. CICO* </b><img src="https://media.giphy.com/media/hvRJCLFzcasrR4ia7z/giphy.gif" width="35"></h1>

📞*Contactos*
<!-- Contactos:START -->
<a href="mailto:quispesullcaluisfernando@gmail.com">
  <img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Gmail" >
</a>
<a href="https://github.com/Gengar-pro">
  <img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">
</a>
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"><br><br>

## 📝 Licencia

Este proyecto está bajo la licencia MIT.  
Consulta el archivo [LICENSE](./LICENSE) para más detalles.


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
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"><br><br>
<p align="center">
  <!-- Fila 1 -->
  <img src="https://github.com/Alex-JC-dot/BombermanUSFX/blob/main/Assets/GamePlay.gif" alt="Captura 1" width="300"/>
  <img src="https://github.com/Alex-JC-dot/BombermanUSFX/blob/main/Assets/GamePlay2.gif" alt="Captura 2" width="300"/>
</p>

<p align="center">
  <!-- Fila 2 -->
  <img src="https://github.com/Alex-JC-dot/BombermanUSFX/raw/main/Assets/WhatsApp%20Image%202025-06-13%20at%2009.48.46%20(4).jpeg" alt="Captura 4" width="300"/>
  <img src="https://github.com/Alex-JC-dot/BombermanUSFX/raw/main/Assets/WhatsApp%20Image%202025-06-13%20at%2009.48.46%20(5).jpeg" alt="Captura 5" width="300"/>
  <img src="https://github.com/Alex-JC-dot/BombermanUSFX/raw/main/Assets/WhatsApp%20Image%202025-06-13%20at%2009.48.46%20(6).jpeg" alt="Captura 6" width="300"/>
</p>
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif"><br><br>

---

## 🌐 *Enlaces acerca del proyecto*

📥 *Enlace al ejecutable ZIP*

[sha256:50588c117b9d13cfb1ed72e7969c25e5f48fa30bd8d4d3f7b7483dd25e52af3e](https://github.com/Alex-JC-dot/BombermanUSFX/releases/download/Tag-1/Windows.zip)

---

## ⚙️ *Equipo Utilizado*
![Unreal Engine](https://img.shields.io/badge/unrealengine-%23313131.svg?style=for-the-badge&logo=unrealengine&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Blender](https://img.shields.io/badge/blender-%23F5792A.svg?style=for-the-badge&logo=blender&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white)
---

💥 ¡Piensa rápido, coloca bien tus bombas y domina el laberinto! 💥

Explota con nosotros el universo de *BomberMan FanGame* y revive la esencia de un clásico desde una nueva dimensión.
