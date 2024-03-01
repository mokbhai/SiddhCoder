import { useContext } from "react";
import { AuthContext } from "../context/AuthContext";

export const useAuthContextt = () => {
  const context = useContext(AuthContext);

  if (!context) {
    throw Error("useAuthContext must be used inside AuthContextProvider");
  }

  return context;
};
