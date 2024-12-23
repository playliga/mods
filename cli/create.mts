#!/usr/bin/env node --no-warnings
/**
 * TBD
 *
 * @module
 */
import * as readline from "node:readline/promises";
import path from "node:path";
import AppInfo from "../package.json" assert { type: "json" };
import { Command } from "commander";

/** @constant */
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

/**
 * TBD
 *
 * @function
 */
async function handler() {
  try {
    const name = await rl.question("Name: ");
    const description = await rl.question("Description: ");
    console.table({ name, description });
  } finally {
    rl.close();
  }
  return Promise.resolve();
}

/**
 * Bootstrapping logic.
 *
 * @name anonymous
 * @function
 */
(async () => {
  const program = new Command();
  program
    .name(path.basename(import.meta.url))
    .description(AppInfo.description)
    .version(AppInfo.version)
    .action(handler);

  try {
    await program.parseAsync(process.argv);
  } catch (error) {
    console.error(error);
    process.exit(1);
  }
})();
