import { createRequire } from "node:module";
import path from "node:path";
const require = createRequire(import.meta.dirname);
const addon = require(path.join(import.meta.dirname, "..", "bin", process.platform, process.arch, "native-glu.node"));
export default addon;
//# sourceMappingURL=index.js.map