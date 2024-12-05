import { enf_conf } from "@/config/env-configs";
import axios from "axios";

export const axios_instance = axios.create({
  baseURL: enf_conf.api_uri,
  withCredentials: true,
});

axios_instance.interceptors.request.use(
  (config) => {
    const session = localStorage.getItem("session");
    if (session) {
      config.headers["Authorization"] = session;
    }
    return config;
  },
  (error) => {
    return Promise.reject(error);
  }
);

export default axios_instance;
