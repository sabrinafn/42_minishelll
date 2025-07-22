# Minishell

This project is part of the School 42 curriculum and was developed as a group project by me and Fernando Loula from School 42 as well.

## Description

The goal of **Minishell** is to create a minimal shell that replicates the basic behavior of Bash. It includes features such as command parsing, environment variable handling, piping, redirections, and signal management.

## Features

<ul>
  <li>Execution of binaries with arguments and environment</li>
  <li>Built-in commands: <code>cd</code>, <code>echo</code>, <code>pwd</code>, <code>export</code>, <code>unset</code>, <code>env</code>, <code>exit</code></li>
  <li>Redirections: <code>&gt;</code>, <code>&gt;&gt;</code>, <code>&lt;</code>, <code>&lt;&lt;</code> (heredoc)</li>
  <li>Pipelines using <code>|</code></li>
  <li>Quote handling (single and double)</li>
  <li>Environment variable expansion with <code>$</code></li>
  <li>Signal handling (<code>CTRL+C</code>, <code>CTRL+D</code>, <code>CTRL+\</code>)</li>
</ul>

## How to Compile and Run

```bash
make

./minishell
