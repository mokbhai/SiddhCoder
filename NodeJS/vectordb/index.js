require("dotenv").config();
const { Pinecone } = require("@pinecone-database/pinecone");
const { GoogleGenerativeAI } = require("@google/generative-ai");

// Initialize Pinecone client
const pinecone = new Pinecone({
  apiKey: process.env.PINECONE_API_KEY,
});

// Initialize Gemini
const genAI = new GoogleGenerativeAI(process.env.GEMINI_API_KEY);

// Function to get embeddings from Gemini
async function getEmbeddings(text) {
  try {
    const model = genAI.getGenerativeModel({ model: "embedding-001" });
    const result = await model.embedContent(text);
    const embedding = await result.embedding;
    return embedding.values; // Extract the values array from the embedding object
  } catch (error) {
    console.error("Error getting embeddings:", error);
    throw error;
  }
}

// Function to create and initialize index
async function initializeIndex() {
  try {
    const index = pinecone.index(process.env.PINECONE_INDEX_NAME);
    return index;
  } catch (error) {
    console.error("Error initializing index:", error);
    throw error;
  }
}

// Function to upsert vectors
async function upsertVectors(vectors) {
  try {
    const index = await initializeIndex();
    const upsertResponse = await index.upsert(vectors);
    return upsertResponse;
  } catch (error) {
    console.error("Error upserting vectors:", error);
    throw error;
  }
}

// Function to query vectors
async function queryVectors(vector, topK = 5) {
  try {
    const index = await initializeIndex();
    const queryResponse = await index.query({
      vector: vector,
      topK: topK,
      includeMetadata: true,
    });
    return queryResponse;
  } catch (error) {
    console.error("Error querying vectors:", error);
    throw error;
  }
}

// Example usage
async function main() {
  try {
    // Example text to embed
    const text = "Hello, world!";

    // Get embeddings
    const embedding = await getEmbeddings(text);

    // Prepare vector for upsert
    const vector = {
      id: "1",
      values: embedding,
      metadata: {
        text: text,
      },
    };

    // Upsert vector
    await upsertVectors([vector]);

    const queryText = "Greetings, universe!";
    
    const queryEmbedding = await getEmbeddings(queryText);

    // Query similar vectors
    const queryResult = await queryVectors(queryEmbedding);
    console.log("Query results:", queryResult);
  } catch (error) {
    console.error("Error in main:", error);
  }
}

main();
