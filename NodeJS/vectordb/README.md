# Vector Database with Pinecone and Gemini

This project demonstrates how to implement a vector database using Pinecone and Google's Gemini AI for text embeddings. It allows you to store text embeddings and perform similarity searches using vector operations.

## Overview

The project uses:

- **Pinecone**: A vector database for storing and querying vector embeddings
- **Google Gemini AI**: For generating text embeddings using the `embedding-001` model
- **Node.js**: As the runtime environment

## Features

- Text to vector embedding conversion using Gemini AI
- Vector storage in Pinecone
- Similarity search using vector operations
- Cosine similarity-based matching

## Prerequisites

- Node.js installed
- Pinecone API key
- Google Gemini API key
- A Pinecone index created with dimension 768 (matching Gemini's embedding-001 model)

## Installation

1. Clone the repository
2. Install dependencies:

```bash
npm install
```

3. Create a `.env` file with your API keys:

```env
PINECONE_API_KEY=your_pinecone_api_key
PINECONE_INDEX_NAME=your_index_name
GEMINI_API_KEY=your_gemini_api_key
```

## How It Works

### 1. Text Embedding Generation

The project uses Gemini's `embedding-001` model to convert text into vector embeddings. Each piece of text is transformed into a 768-dimensional vector that captures its semantic meaning.

```javascript
const model = genAI.getGenerativeModel({ model: "embedding-001" });
const result = await model.embedContent(text);
const embedding = await result.embedding;
```

### 2. Vector Storage

The generated embeddings are stored in Pinecone with associated metadata. Each vector entry includes:

- A unique ID
- The vector values (768 dimensions)
- Metadata (original text)

```javascript
const vector = {
  id: "1",
  values: embedding,
  metadata: {
    text: text,
  },
};
```

### 3. Similarity Search

The system can perform similarity searches by:

1. Converting the query text into an embedding
2. Finding the most similar vectors in the database using cosine similarity
3. Returning the matching results with their metadata

```javascript
const queryResult = await queryVectors(queryEmbedding);
```

## Usage Example

The main function demonstrates a complete workflow:

1. Convert text to embedding:

```javascript
const text = "Hello, world!";
const embedding = await getEmbeddings(text);
```

2. Store the embedding:

```javascript
await upsertVectors([vector]);
```

3. Perform a similarity search:

```javascript
const queryText = "Greetings, universe!";
const queryEmbedding = await getEmbeddings(queryText);
const results = await queryVectors(queryEmbedding);
```

## Running the Project

Start the application:

```bash
npm start
```

## Technical Details

- **Embedding Model**: Gemini's `embedding-001` (768 dimensions)
- **Vector Database**: Pinecone
- **Similarity Metric**: Cosine similarity
- **Vector Operations**: Upsert and Query

## Error Handling

The implementation includes comprehensive error handling for:

- API connection issues
- Invalid vector dimensions
- Failed embedding generation
- Database operation errors

## Best Practices

1. Always ensure your Pinecone index dimension (768) matches the embedding model's output dimension
2. Handle API rate limits appropriately
3. Implement proper error handling for production use
4. Consider batch operations for multiple vectors
5. Implement proper cleanup and resource management

## Limitations

- The embedding model has a maximum input token limit
- API rate limits may apply
- Vector similarity search performance depends on index size
- Storage costs may vary based on usage

## Future Improvements

- Add batch processing capabilities
- Implement vector deletion
- Add more sophisticated query options
- Implement caching for frequently accessed embeddings
- Add support for different embedding models
- Implement vector update operations
