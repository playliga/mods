#!/usr/bin/env node --no-warnings
/**
 * Bootstraps a new mod.
 *
 * @module
 */
import * as readline from "node:readline/promises";
import fs from "node:fs";
import path from "node:path";
import sea from "node:sea";
import AppInfo from "../package.json" assert { type: "json" };
import { Command } from "commander";

/** @constant */
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

/**
 * Replaces characters in strings that are
 * illegal or unsafe for filenames.
 *
 * @param input       The input string.
 * @param replacement The replacement string.
 * @function
 */
function sanitize(input: string, replacement = "-") {
  const illegal = /[/?<>\\:*|\s"]/g;
  const reserved = /^\.+$/;
  const windowsReserved = /^(con|prn|aux|nul|com[0-9]|lpt[0-9])(\..*)?$/i;
  const windowsTrailing = /[. ]+$/;

  return input
    .replace(illegal, replacement)
    .replace(reserved, replacement)
    .replace(windowsReserved, replacement)
    .replace(windowsTrailing, replacement);
}

/**
 * Prompts the user for their mod's information
 * and bootstraps the project directory
 * and metadata json file.
 *
 * @function
 */
async function handler() {
  const name = await rl.question(">> Enter the name of your mod: ");
  const author = await rl.question(">> Who is the author of this mod? ");
  const description = await rl.question(">> Provide a brief description of your mod: ");
  const metadata = { name: sanitize(name), author, description };

  const projectPath = path.join("custom", metadata.name);
  const metadataPath = path.join(projectPath, "metadata.json");

  process.stdout.write(`>> Creating "${projectPath}"... `);
  await fs.promises.mkdir(projectPath, { recursive: true });
  process.stdout.write("Done.\n");

  process.stdout.write(`>> Creating "${metadataPath}"... `);
  await fs.promises.writeFile(metadataPath, JSON.stringify(metadata, null, 2), "utf-8");
  process.stdout.write("Done.\n");

  // @todo: print out instructions on what to do next
  // @todo: copy save_0.db, if found
  //
  // in prod we do not want to close the terminal
  // window immediately after work is done
  if (sea.isSea()) {
    console.log("Press any key to exit...");
    process.stdin.setRawMode(true);
    await new Promise((resolve) => process.stdin.once("data", resolve));
  }

  rl.close();
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
