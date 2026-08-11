# 421 — Full 42 Cursus Mirror

Independent lyff nested repo with **complete source** for every public project from
[anaiel/-42projects](https://github.com/anaiel/-42projects), including all linked
project repositories (not just README links).

> École 42 · peer-to-peer · project-based · The Norm applies to C projects  
> See `resources/norme.en.pdf` and `resources/ORIGINAL_OVERVIEW.md`.

**Remote:** [github.com/lyffseba/421](https://github.com/lyffseba/421)

## Layout

```text
421/
├── README.md
├── resources/
│   ├── norme.en.pdf
│   └── ORIGINAL_OVERVIEW.md
├── piscine_reloaded/          # Cursus start
├── libft/
├── get_next_line/
├── fillit/
├── ft_printf/                 # Algo branch
├── push_swap/
├── lem_in/
├── corewar/
├── fdf/                       # Graphics branch
├── fractol/
├── roger_skyline_1/           # SysAdmin
├── php_piscine/               # Web
└── workshops_machinelearning/ # 42AI ML workshops
```

## Project tracker

Grades from the original overview. **100** = full mandatory; **101–125** = bonuses.

### 🚩 Cursus start

| Project | Path | Goals | Solo/Group | Grade |
|---------|------|-------|------------|-------|
| 42 Commandements | — | Code of conduct | Solo | 100 |
| Piscine Reloaded | `piscine_reloaded/` | Basics of C | Solo | 100 |
| Libft | `libft/` | Basics of C, static libraries | Solo | 125 |
| Get_Next_Line | `get_next_line/` | FDs, parsing, bufferisation | Solo | 112 |
| Fillit | `fillit/` | Basic algorithm, I/O | Group | 100 |

### 🔱 Algo branch

| Project | Path | Goals | Solo/Group | Grade |
|---------|------|-------|------------|-------|
| ft_printf | `ft_printf/` | Parsing, variadic functions | Group | 110 |
| Push_swap | `push_swap/` | Sorting, stacks | Solo | 125 |
| Lem-in | `lem_in/` | Graph search, max flow | Group | 124 |
| Corewar | `corewar/` | Compiler, VM, assembler, viz | Group | 125 |

### 🎮 Graphics branch

| Project | Path | Goals | Solo/Group | Grade |
|---------|------|-------|------------|-------|
| FdF | `fdf/` | mlx, segments, 3D→2D | Group | 125 |
| Fract'ol | `fractol/` | 2D programming, optimization | Solo | 117 |

### 🔐 Systems administration

| Project | Path | Goals | Solo/Group | Grade |
|---------|------|-------|------------|-------|
| Init | — (no public source) | Unix, sysadmin | Solo | 100 |
| Roger-Skyline-1 | `roger_skyline_1/` | Unix, networks | Solo | 60 |
| Docker-1 | — (unfinished upstream) | Containers, DevOps | Solo | — |

### 🌐 Web branch

| Project | Path | Goals | Solo/Group | Grade |
|---------|------|-------|------------|-------|
| Piscine PHP | `php_piscine/` | HTML, PHP, SQL, OOP | Solo | 104 |
| Camagru / Matcha / Hypertube | — (unfinished upstream) | Web apps | — | — |

### 💡 Machine learning (42AI)

| Path | Notes |
|------|-------|
| `workshops_machinelearning/` | 14-week workshops; k-means presentation included |

## Quick build samples

```bash
# Libft
make -C libft && make -C libft fclean

# Get next line / printf / push_swap / fillit (when Makefile present)
make -C ft_printf
make -C push_swap
make -C fillit
```

C projects follow **the Norm** (`resources/norme.en.pdf`): ≤25 lines/function, ≤5 functions per `.c`, Makefile must not relink, etc.

## Provenance

- Overview & Norm: [anaiel/-42projects](https://github.com/anaiel/-42projects)
- Per-project sources mirrored from the public `anaiel/*` repos linked in that overview
- This tree is a **local educational mirror** for the lyff portfolio hub (`~/lyff/421`)
- Upstream author: [anaiel](https://github.com/anaiel) @ 42

## Not included

No public upstream source was linked for: Init writeups, Docker-1, Camagru, Matcha, Hypertube.
