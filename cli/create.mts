#!/usr/bin/env node --no-warnings
/**
 * TBD
 *
 * @module
 */
import path from 'node:path';
import AppInfo from "../package.json" assert { type: "json" };
import { Command } from "commander";

/**
 * TBD
 *
 * @function
 */
async function handler() {
  console.log('here');
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
