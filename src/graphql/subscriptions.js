/* eslint-disable */
// this is an auto generated file. This will be overwritten

export const onCreateMessage = /* GraphQL */ `
  subscription OnCreateMessage {
    onCreateMessage {
      id
      username
      content
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const onUpdateMessage = /* GraphQL */ `
  subscription OnUpdateMessage {
    onUpdateMessage {
      id
      username
      content
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const onDeleteMessage = /* GraphQL */ `
  subscription OnDeleteMessage {
    onDeleteMessage {
      id
      username
      content
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const onCreateUser = /* GraphQL */ `
  subscription OnCreateUser {
    onCreateUser {
      id
      username
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const onUpdateUser = /* GraphQL */ `
  subscription OnUpdateUser {
    onUpdateUser {
      id
      username
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const onDeleteUser = /* GraphQL */ `
  subscription OnDeleteUser {
    onDeleteUser {
      id
      username
      roomid {
        id
        movie
        tilte
        numberofmember
        privatepassword
        users {
          nextToken
        }
        time
        reservedtime
        messages {
          nextToken
        }
      }
    }
  }
`;
export const onCreateRoom = /* GraphQL */ `
  subscription OnCreateRoom {
    onCreateRoom {
      id
      movie
      tilte
      numberofmember
      privatepassword
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
      messages {
        items {
          id
          username
          content
        }
        nextToken
      }
    }
  }
`;
export const onUpdateRoom = /* GraphQL */ `
  subscription OnUpdateRoom {
    onUpdateRoom {
      id
      movie
      tilte
      numberofmember
      privatepassword
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
      messages {
        items {
          id
          username
          content
        }
        nextToken
      }
    }
  }
`;
export const onDeleteRoom = /* GraphQL */ `
  subscription OnDeleteRoom {
    onDeleteRoom {
      id
      movie
      tilte
      numberofmember
      privatepassword
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
      messages {
        items {
          id
          username
          content
        }
        nextToken
      }
    }
  }
`;
